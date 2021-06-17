/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:02:06 by rzukale           #+#    #+#             */
/*   Updated: 2019/11/02 15:07:43 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	x;

	x = n;
	if (x < 0)
	{
		ft_putchar_fd('-', fd);
		x = -x;
	}
	if (x < 10)
	{
		ft_putchar_fd('0' + x, fd);
		return ;
	}
	ft_putnbr_fd(x / 10, fd);
	ft_putnbr_fd(x % 10, fd);
}
