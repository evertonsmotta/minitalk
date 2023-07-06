/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfpointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:24:54 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/01/21 12:26:20 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointerlen(uintptr_t address)
{
	int	len;

	len = 0;
	while (address != 0)
	{
		len++;
		address = address / 16;
	}
	return (len);
}

void	ft_haxapointer(uintptr_t address)
{
	if (address >= 16)
	{
		ft_haxapointer(address / 16);
		ft_haxapointer(address % 16);
	}
	else
	{
		if (address < 10)
			ft_putchar_fd((address + '0'), 1);
		else
			ft_putchar_fd((address - 10 + 'a'), 1);
	}
}

int	ft_pointer(unsigned long long address)
{
	int	hexaptr;

	hexaptr = 0;
	if (address == 0)
	{
		hexaptr += ft_iputstr_fd("(nil)", 1);
	}
	else
	{
		hexaptr = ft_iputstr_fd("0x", 1);
		ft_haxapointer(address);
		hexaptr += ft_pointerlen(address);
	}
	return (hexaptr);
}
/*
int	ft_pointer(unsigned long long address)
{
	int	hexaptr;

	hexaptr = ft_iputstr_fd("0x", 1);
	if (address == 0)
	{
		hexaptr += ft_iputstr_fd("(nil)", 1);
		return ;
	}
	else
	{
		ft_haxapointer(address);
		hexaptr += ft_pointerlen(address);
	}
	return (hexaptr);
}
*/
