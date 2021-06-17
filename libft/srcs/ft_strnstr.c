/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:11:56 by rzukale           #+#    #+#             */
/*   Updated: 2019/11/02 15:00:55 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_length;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	needle_length = ft_strlen(needle);
	if (len == 0)
		return (NULL);
	while (haystack[i] && i <= (len - needle_length))
	{
		if (!(ft_strncmp((haystack + i), needle, needle_length)))
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
