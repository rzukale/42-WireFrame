/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:17:05 by rzukale           #+#    #+#             */
/*   Updated: 2020/07/28 15:02:20 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_camera	*init_camera(t_env *env)
{
	t_camera *camera;

	if (!(camera = (t_camera*)malloc(sizeof(t_camera))))
		display_error(-1);
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->x_offset = 0;
	camera->y_offset = 0;
	camera->z_value = 1;
	camera->zoom = ft_min((env->width / 2 / env->map->width / 2),
						(env->height / 2 / env->map->height / 2));
	camera->iso = 1;
	return (camera);
}

t_image		*new_image(t_env *env)
{
	t_image		*image;

	if (!(image = (t_image*)malloc(sizeof(t_image))))
		display_error(-1);
	image->image = mlx_new_image(env->mlx, env->width, env->height);
	image->buffer = mlx_get_data_addr(image->image,
			&image->bits_per_pixel, &image->size_line, &image->endian);
	return (image);
}

t_env		*initialise_env(void)
{
	t_env	*env;

	if (!(env = (t_env*)malloc(sizeof(t_env))))
		display_error(-1);
	if ((env->mlx = mlx_init()) == NULL)
		display_error(-4);
	if (!(env->map = (t_map*)malloc(sizeof(t_map))))
		display_error(-1);
	env->map->list = NULL;
	env->window = NULL;
	env->map->width = 0;
	env->map->height = 0;
	env->map->max = 0;
	env->map->min = 0;
	env->width = 0;
	env->height = 0;
	env->colors.base_color = 0x008000;
	env->colors.mid_color = 0xD2691E;
	env->colors.top_color = 0xFFFFFF;
	return (env);
}

void		setup_window(t_env **env, char *title)
{
	char	*tmp;
	int		x;
	int		y;

	tmp = ft_strjoin("FdF - ", title);
	x = (*env)->map->width;
	y = (*env)->map->height;
	if (x * 50 >= 2560)
		(*env)->width = 2560;
	else if (x * 50 <= 600)
		(*env)->width = 600;
	else
		(*env)->width = x * 50;
	if (y * 50 >= 1440)
		(*env)->height = 1440;
	else if (y * 50 <= 800)
		(*env)->height = 800;
	else
		(*env)->height = y * 50;
	(*env)->window = mlx_new_window((*env)->mlx,
					(*env)->width, (*env)->height, tmp);
	(*env)->camera = init_camera(*env);
	(*env)->image = new_image((*env));
	free(tmp);
}

void		free_all(t_env *env)
{
	if (env)
	{
		free_list(&env->map->list);
		free(env->map);
		free(env->camera);
		mlx_destroy_window(env->mlx, env->window);
		free(env->mlx);
		free(env);
	}
	exit(0);
}
