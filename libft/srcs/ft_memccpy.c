/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:25:37 by rzukale           #+#    #+#             */
/*   Updated: 2019/10/27 19:16:15 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*src_cpy;
	unsigned char	*dst_cpy;

	i = 0;
	src_cpy = (unsigned char *)src;
	dst_cpy = (unsigned char *)dst;
	while (i < n)
	{
		dst_cpy[i] = src_cpy[i];
		if (dst_cpy[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
