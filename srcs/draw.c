/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:39:46 by rzukale           #+#    #+#             */
/*   Updated: 2020/07/28 15:52:49 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_image(t_env *env)
{
	ft_bzero(env->image->buffer, env->width * env->height *
			env->image->bits_per_pixel / 8);
}

void	render(t_env *env)
{
	int			x;
	int			y;
	t_line		temp;

	clear_image(env);
	y = 0;
	while (y < env->map->height)
	{
		x = 0;
		while (x < env->map->width)
		{
			temp = setup_line((get_vector(x, y, &env->map->list)), env);
			if ((x + 1) < env->map->width)
				draw_line(temp, setup_line((get_vector(x + 1, y,
				&env->map->list)), env), env);
			if ((y + 1) < env->map->height)
				draw_line(temp, setup_line((get_vector(x, y + 1,
				&env->map->list)), env), env);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->mlx, env->window, env->image->image, 0, 0);
	print_menu(env);
}

void	pixel_put(t_env *env, int x, int y, int color)
{
	int	i;

	if (x >= 0 && x < env->width && y >= 0 && y < env->height)
	{
		i = (y * env->image->size_line) + (x * 4);
		if (env->image->endian == 1)
		{
			env->image->buffer[i + 0] = (color >> 24);
			env->image->buffer[i + 1] = (color >> 16) & 0xFF;
			env->image->buffer[i + 2] = (color >> 8) & 0xFF;
			env->image->buffer[i + 3] = (color) & 0xFF;
		}
		else if (env->image->endian == 0)
		{
			env->image->buffer[i + 0] = (color) & 0xFF;
			env->image->buffer[i + 1] = (color >> 8) & 0xFF;
			env->image->buffer[i + 2] = (color >> 16) & 0xFF;
			env->image->buffer[i + 3] = (color >> 24);
		}
	}
}

void	draw_line(t_line start, t_line end, t_env *env)
{
	t_line	current;
	t_delta	delta;
	int		pixels;

	delta.x = end.x - start.x;
	delta.y = end.y - start.y;
	pixels = sqrt((delta.x * delta.x) + (delta.y * delta.y));
	delta.x /= pixels;
	delta.y /= pixels;
	current = start;
	while (pixels)
	{
		pixel_put(env, (int)current.x, (int)current.y,
			get_color(current, start, end, delta));
		current.x += delta.x;
		current.y += delta.y;
		pixels--;
	}
}

t_line	setup_line(t_vector *vector, t_env *env)
{
	t_line	temp;

	temp.x = (float)(vector->x * env->camera->zoom);
	temp.y = (float)(vector->y * env->camera->zoom);
	temp.z = (float)(vector->z * (env->camera->zoom * env->camera->z_value));
	temp.x -= (env->map->width * env->camera->zoom) / 2;
	temp.y -= (env->map->height * env->camera->zoom) / 2;
	temp.color = vector->color;
	rotate_x(&temp.y, &temp.z, env->camera->alpha);
	rotate_y(&temp.x, &temp.z, env->camera->beta);
	rotate_z(&temp.x, &temp.y, env->camera->gamma);
	if (env->camera->iso)
		isometric(&temp.x, &temp.y, temp.z);
	temp.x += env->width / 2 + env->camera->x_offset;
	temp.y += env->height / 2 + env->camera->y_offset;
	return (temp);
}
