/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 22:47:07 by rzukale           #+#    #+#             */
/*   Updated: 2020/07/28 15:01:31 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_image(int key, t_env *env)
{
	if (key == 126)
		env->camera->y_offset -= 10;
	if (key == 125)
		env->camera->y_offset += 10;
	if (key == 123)
		env->camera->x_offset -= 10;
	if (key == 124)
		env->camera->x_offset += 10;
	render(env);
}

void	modify_height(int key, t_env *env)
{
	if (key == 6 && env->camera->z_value < 25)
		env->camera->z_value += 1;
	if (key == 7 && env->camera->z_value > -25)
		env->camera->z_value -= 1;
	render(env);
}

void	rotate_image(int key, t_env *env)
{
	if (key == 13)
		env->camera->alpha += 0.5;
	if (key == 1)
		env->camera->alpha -= 0.5;
	if (key == 0)
		env->camera->beta -= 0.5;
	if (key == 2)
		env->camera->beta += 0.5;
	render(env);
}

void	zoom_image(int key, t_env *env)
{
	if (key == 12 && env->camera->zoom < 25)
		env->camera->zoom += 1;
	if (key == 14)
	{
		if (env->camera->zoom == 1)
			env->camera->zoom = 1;
		else
			env->camera->zoom -= 1;
	}
	render(env);
}

void	reset_camera(t_env *env)
{
	env->camera->alpha = 0;
	env->camera->beta = 0;
	env->camera->gamma = 0;
	env->camera->x_offset = 0;
	env->camera->y_offset = 0;
	env->camera->z_value = 1;
	env->camera->zoom = ft_min((env->width / 2 / env->map->width / 2),
						(env->height / 2 / env->map->height / 2));
	env->camera->iso = 1;
	render(env);
}
