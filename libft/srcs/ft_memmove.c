/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:36:24 by rzukale           #+#    #+#             */
/*   Updated: 2019/10/17 17:28:57 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	size_t	i;
	char	*cpysrc;
	char	*cpydst;

	cpysrc = (char*)src;
	cpydst = (char*)dest;
	if (src == dest)
		return (dest);
	if (src < dest)
	{
		i = count;
		while (i-- > 0)
			cpydst[i] = cpysrc[i];
	}
	else
	{
		i = 0;
		while (i < count)
		{
			cpydst[i] = cpysrc[i];
			i++;
		}
	}
	return (dest);
}
