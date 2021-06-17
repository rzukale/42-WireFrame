/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:36:35 by rzukale           #+#    #+#             */
/*   Updated: 2020/06/01 13:42:47 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		assign_color(t_lst **temp, t_env *env, int random)
{
	t_lst	*tmp;

	tmp = *temp;
	if (random == 0)
	{
		if (tmp->data->color == 0 && tmp->data->z == env->map->min)
			tmp->data->color = env->colors.base_color;
		else if (tmp->data->color == 0 && tmp->data->z == env->map->max)
			tmp->data->color = env->colors.top_color;
		else if (tmp->data->color == 0 && (tmp->data->z < env->map->max &&
				tmp->data->z > env->map->min))
			tmp->data->color = env->colors.mid_color;
	}
	if (random == 1)
	{
		if (tmp->data->z == env->map->min)
			tmp->data->color = env->colors.base_color;
		else if (tmp->data->z == env->map->max)
			tmp->data->color = env->colors.top_color;
		else if (tmp->data->z < env->map->max && tmp->data->z > env->map->min)
			tmp->data->color = env->colors.mid_color;
	}
}

void		fill_colors(t_env *env, int random)
{
	t_lst *tmp;

	tmp = env->map->list;
	if (tmp)
	{
		while (tmp->next != NULL)
		{
			assign_color(&tmp, env, random);
			tmp = tmp->next;
		}
	}
}

double		get_percentage(int current, int start, int end)
{
	double	distance;
	double	placement;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int			get_gradient(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int			get_color(t_line current, t_line start, t_line end, t_delta delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		percentage = get_percentage(current.x, start.x, end.x);
	else
		percentage = get_percentage(current.y, start.y, end.y);
	red = get_gradient((start.color >> 16) & 0xFF,
						(end.color >> 16) & 0xFF,
						percentage);
	green = get_gradient((start.color >> 8) & 0xFF,
						(end.color >> 8) & 0xFF,
						percentage);
	blue = get_gradient(start.color & 0xFF,
						end.color & 0xFF,
						percentage);
	return ((red << 16) | (green << 8) | blue);
}
