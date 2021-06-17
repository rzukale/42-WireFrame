/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 22:45:50 by rzukale           #+#    #+#             */
/*   Updated: 2020/06/01 14:05:21 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_menu(t_env *env)
{
	char	*str;
	int		x;
	int		y;

	x = 10;
	y = 5;
	str = "Move Image: Arrow keys";
	mlx_string_put(env->mlx, env->window, x, y, 0x437613, str);
	str = "Rotate image: 'W' 'S' 'A' 'D' Keys";
	mlx_string_put(env->mlx, env->window, x, y + 20, 0x437613, str);
	str = "Zoom: 'Q' +; 'E' -";
	mlx_string_put(env->mlx, env->window, x, y + 40, 0x437613, str);
	str = "Increase height: 'Z' +; 'X' -";
	mlx_string_put(env->mlx, env->window, x, y + 60, 0x437613, str);
	str = "Random Color: 'T'";
	mlx_string_put(env->mlx, env->window, x, y + 80, 0x437613, str);
	str = "Reset camera: 'R'; Switch projection: 'Y'";
	mlx_string_put(env->mlx, env->window, x, y + 100, 0x437613, str);
	str = "Exit with 'ESC'";
	mlx_string_put(env->mlx, env->window, x, y + 120, 0x437613, str);
}

void	switch_projection(t_env *env)
{
	if (env->camera->iso == 1)
		env->camera->iso = 0;
	else
		env->camera->iso = 1;
	render(env);
}
