/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 14:31:15 by rzukale           #+#    #+#             */
/*   Updated: 2020/03/12 22:38:43 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		free_list(t_lst **begin_list)
{
	t_lst *next;
	t_lst *list;

	list = *begin_list;
	if (list)
	{
		while (list)
		{
			next = list->next;
			free(list->data);
			ft_memdel((void**)&list);
			list = next;
		}
	}
	*begin_list = NULL;
}

t_lst		*ft_create_elem(void *data)
{
	t_lst	*list;

	list = NULL;
	if (!(list = (t_lst*)malloc(sizeof(t_lst))))
		display_error(-1);
	if (list)
	{
		list->data = data;
		list->next = NULL;
	}
	return (list);
}

void		ft_list_push_back(t_lst **begin_list, t_vector *data)
{
	t_lst *push;
	t_lst *list;

	push = *begin_list;
	if (push != NULL)
	{
		while (push->next != NULL)
		{
			push = push->next;
		}
		if ((list = ft_create_elem(data)))
		{
			push->next = list;
		}
	}
	else
	{
		*begin_list = ft_create_elem(data);
	}
}

t_lst		*join_lists(t_lst **list1, t_lst *list2)
{
	t_lst	*push;
	t_lst	*head;

	push = *list1;
	if (push)
	{
		head = *list1;
		while (push->next != NULL)
			push = push->next;
	}
	else
	{
		head = list2;
		return (head);
	}
	push->next = list2;
	return (head);
}
