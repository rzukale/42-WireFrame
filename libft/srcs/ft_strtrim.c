/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:09:17 by rzukale           #+#    #+#             */
/*   Updated: 2019/10/29 18:58:09 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	i;
	size_t	j;
	char	*str;

	j = 0;
	start = 0;
	if (!s)
		return (NULL);
	while (s[start] == '\t' || s[start] == '\n' || s[start] == ' ')
		start++;
	i = ft_strlen(s);
	if (start != i)
	{
		while (s[i - 1] == '\t' || s[i - 1] == '\n' || s[i - 1] == ' ')
			i--;
	}
	if (!(str = ft_memalloc(sizeof(char) * (i - start) + 1)))
		return (NULL);
	while (start < i)
		str[j++] = s[start++];
	str[j] = '\0';
	return (str);
}
