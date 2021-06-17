/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:15:56 by rzukale           #+#    #+#             */
/*   Updated: 2019/10/29 20:15:14 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t count)
{
	size_t i;

	i = 0;
	while (src[i] != '\0' && i < count)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < count)
		dest[i++] = '\0';
	return (dest);
}
