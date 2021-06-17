/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:53:45 by rzukale           #+#    #+#             */
/*   Updated: 2019/10/17 17:14:53 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int ch, size_t count)
{
	size_t			i;
	unsigned char	*tmp;

	tmp = (unsigned char*)ptr;
	i = 0;
	while (i < count)
	{
		if (tmp[i] == (unsigned char)ch)
			return (tmp + i);
		i++;
	}
	return (NULL);
}
