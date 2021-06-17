/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 20:54:08 by rzukale           #+#    #+#             */
/*   Updated: 2019/12/10 12:22:33 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (!(dest = ft_strnew(n)))
		return (NULL);
	while (s1[i] && i < n)
	{
		dest[i] = s1[i];
		i++;
	}
	return (dest);
}
