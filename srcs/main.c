/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 21:46:33 by rzukale           #+#    #+#             */
/*   Updated: 2020/06/01 13:43:20 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_error(int nbr)
{
	if (nbr == -1)
		ft_putstr_fd("Memory allocation failed!\n", 2);
	else if (nbr == -2)
		ft_putstr_fd("Unable to open file!\n", 2);
	else if (nbr == -3)
		ft_putstr_fd("File not valid!\n", 2);
	else if (nbr == -4)
		ft_putstr_fd("MLX failed to initialize!\n", 2);
	exit(0);
}

int		choose_random_color(void)
{
	int		red;
	int		green;
	int		blue;

	red = rand() % 256;
	green = rand() % 256;
	blue = rand() % 256;
	return ((red << 16) | (green << 8) | blue);
}

void	random_color(t_env *env)
{
	env->colors.base_color = choose_random_color();
	env->colors.mid_color = choose_random_color();
	env->colors.top_color = choose_random_color();
	fill_colors(env, 1);
	render(env);
}

int		read_input(int key, t_env *env)
{
	if (key == 53)
		free_all(env);
	if (key == 13 || key == 1 || key == 0 || key == 2)
		rotate_image(key, env);
	if (key == 12 || key == 14)
		zoom_image(key, env);
	if (key == 126 || key == 125 || key == 123 || key == 124)
		move_image(key, env);
	if (key == 6 || key == 7)
		modify_height(key, env);
	if (key == 15)
		reset_camera(env);
	if (key == 16)
		switch_projection(env);
	if (key == 17)
		random_color(env);
	return (1);
}

int		main(int argc, char **argv)
{
	t_env	*env;

	if (argc == 2)
	{
		env = initialise_env();
		parse_file(argv[1], env);
		setup_window(&env, argv[1]);
		render(env);
		mlx_hook(env->window, 2, 0, read_input, env);
		mlx_loop(env->mlx);
	}
	else
		ft_putstr_fd("Usage: ./fdf <file_name>\n", 2);
	return (0);
}
