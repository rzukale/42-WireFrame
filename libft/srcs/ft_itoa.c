/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:46:58 by rzukale           #+#    #+#             */
/*   Updated: 2019/11/04 20:25:50 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	size_t		i;
	size_t		nbr;
	char		*tmp;

	nbr = n;
	i = ft_int_length(n);
	if (!(tmp = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	if (n < 0)
		tmp[0] = '-';
	tmp[i] = '\0';
	i--;
	if (n == 0)
		tmp[i] = '0';
	while (n)
	{
		tmp[i] = '0' + n % 10 * (n < 0 ? -1 : 1);
		i--;
		n /= 10;
	}
	return (tmp);
}
