/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:50:10 by rzukale           #+#    #+#             */
/*   Updated: 2020/07/28 14:05:07 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_lst	*fill_map(char *str, int y)
{
	char	**array;
	char	**tmp;
	t_lst	*list;
	int		i;

	i = 0;
	list = NULL;
	array = ft_strsplit(str, ' ');
	while (array[i] != NULL)
	{
		if ((validate_word(array[i])) == 2)
		{
			tmp = ft_strsplit(array[i], ',');
			ft_list_push_back(&list, new_vector(y, i, ft_atoi(tmp[0]),
							ft_atoi(tmp[1])));
			cleanup(tmp);
		}
		else
			ft_list_push_back(&list, new_vector(y, i,
							ft_atoi(array[i]), 0));
		i++;
	}
	cleanup(array);
	return (list);
}

void	isometric(float *x, float *y, int z)
{
	float last_x;
	float last_y;

	last_x = *x;
	last_y = *y;
	*x = (last_x - last_y) * cos(0.523599);
	*y = (last_x + last_y) * sin(0.523599) - z;
}

void	rotate_x(float *y, int *z, double alpha)
{
	float	last_y;

	last_y = *y;
	*y = last_y * cos(alpha) + *z * sin(alpha);
	*z = -last_y * sin(alpha) + *z * cos(alpha);
}

void	rotate_y(float *x, int *z, double beta)
{
	float	last_x;

	last_x = *x;
	*x = last_x * cos(beta) + *z * sin(beta);
	*z = -last_x * sin(beta) + *z * cos(beta);
}

void	rotate_z(float *x, float *y, double gamma)
{
	float	last_x;
	float	last_y;

	last_x = *x;
	last_y = *y;
	*x = last_x * cos(gamma) - last_y * sin(gamma);
	*y = last_x * sin(gamma) + last_y * cos(gamma);
}
