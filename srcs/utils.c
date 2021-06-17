/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:10:46 by rzukale           #+#    #+#             */
/*   Updated: 2020/03/12 21:43:53 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	find_min_max(t_map *map)
{
	int		min;
	int		max;
	t_lst	*tmp;

	tmp = map->list;
	min = 0;
	max = 0;
	while (tmp->next != NULL)
	{
		if (min == 0 && max == 0)
		{
			min = tmp->data->z;
			max = tmp->data->z;
		}
		if (min > tmp->data->z)
			min = tmp->data->z;
		if (max < tmp->data->z)
			max = tmp->data->z;
		tmp = tmp->next;
	}
	map->min = min;
	map->max = max;
}

void	cleanup(char **array)
{
	int i;

	i = 0;
	while (array[i] != NULL)
	{
		ft_strdel(&array[i]);
		i++;
	}
	free(array);
}

float	ft_max(float a, float b)
{
	return (a > b ? a : b);
}

int		ft_min(int a, int b)
{
	return (a < b ? a : b);
}

float	get_sign(float i)
{
	return (i < 0) ? -i : i;
}
