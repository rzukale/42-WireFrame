/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:46:18 by rzukale           #+#    #+#             */
/*   Updated: 2020/03/11 19:47:17 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector	*get_vector(int x, int y, t_lst **list)
{
	t_lst *temp;

	temp = *list;
	if (temp)
	{
		while (temp != NULL)
		{
			if (temp->data->x == x && temp->data->y == y)
				return (temp->data);
			temp = temp->next;
		}
	}
	return (NULL);
}

t_vector	*new_vector(int y, int x, int z, int color)
{
	t_vector *data;

	if (!(data = ft_memalloc(sizeof(t_vector*))))
		display_error(-1);
	if (color != 0)
		data->color = color;
	else
		data->color = 0;
	data->x = x;
	data->y = y;
	data->z = z;
	return (data);
}
