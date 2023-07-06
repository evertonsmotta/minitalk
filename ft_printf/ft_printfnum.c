/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:57:01 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/01/21 12:35:11 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen(long nbr, int base)
{
	int	i;

	i = 1;
	if (nbr < 0)
	{
		i++;
		nbr = -nbr;
	}
	while (nbr >= base)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	nbr;

	nbr = n;
	if (n >= 0)
	{
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + 48, fd);
	}
	else if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	return (ft_nbrlen(nbr, 10));
}

size_t	ft_uputnbr_fd(size_t n, int fd)
{
	size_t	nbr;

	nbr = n;
	if (n >= 0)
	{
		if (n > 9)
			ft_uputnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + 48, fd);
	}
	else
	{
		ft_putchar_fd('-', fd);
		ft_uputnbr_fd(-n, fd);
	}
	return (ft_nbrlen(nbr, 10));
}
