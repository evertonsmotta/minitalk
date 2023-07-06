/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:24:08 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/07/06 17:28:30 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_category(va_list ap, const char category)
{
	int	output;

	output = 0;
	if (category == 'c')
		output = (ft_putchari_fd(va_arg(ap, int), 1));
	else if (category == 's')
		output = ft_iputstr_fd(va_arg(ap, char *), 1);
	else if (category == 'p')
		output = ft_pointer(va_arg(ap, unsigned long long));
	else if (category == 'd' || category == 'i')
		output = ft_putnbri_fd(va_arg(ap, int), 1);
	else if (category == 'u')
		output = ft_uputnbr_fd(va_arg(ap, unsigned int), 1);
	else if (category == 'x' || category == 'X')
		output = ft_printfhexa(va_arg(ap, unsigned int), category);
	else if (category == '%')
		output = ft_putchari_fd('%', 1);
	return (output);
}

int	ft_printf(const char *fstarg, ...)
{
	size_t	i;
	va_list	ap;
	int		output;

	i = 0;
	output = 0;
	va_start(ap, fstarg);
	while (fstarg[i])
	{
		if (fstarg[i] == '%')
		{
			output += ft_category(ap, fstarg[i + 1]);
			i++;
		}
		else
			output += ft_putchari_fd(fstarg[i], 1);
		i++;
	}
	va_end(ap);
	return (output);
}
/*
#include <stdio.h>
int	main(void)
{
	char	string[] = "New String";
	int		returnlen;
	void *j = NULL
	
	returnlen = ft_printf("Simple Print\n");
	printf("Len Simple Print: %d\n", returnlen);
	returnlen = printf("Simple Print\n");
	printf("Len Simple Print: %d\n", returnlen);
	
	printf("------------------------\n");
	
	returnlen = ft_printf("Char: %c%c%c\n", 'A', 'B', 'C');
	printf("Len Char: %d\n", returnlen);
	returnlen = printf("Char: %c%c%c\n", 'A', 'B', 'C');
	printf("Len Char: %d\n", returnlen);
	
	printf("------------------------\n");
	
	returnlen = ft_printf("String: %s\n", string);
	printf("Len String: %d\n", returnlen);
	returnlen = printf("String: %s\n", string);
	printf("Len String: %d\n", returnlen);
	
	printf("------------------------\n");
	
	returnlen = ft_printf("Pointer: %p\n", j);
	printf("Len Pointer: %d\n", returnlen);
	returnlen = printf("Pointer: %p\n", j);
	printf("Len Pointer: %d\n", returnlen);
	
	printf("------------------------\n");	
	
	returnlen = ft_printf("Decimal: %d\n", 100);
	printf("Len Decimal: %d\n", returnlen);
	returnlen = printf("Decimal: %d\n", 100);
	printf("Len Decimal: %d\n", returnlen);
		
	printf("------------------------\n");	
	
	returnlen = ft_printf("Integer: %i\n", 3000);
	printf("Len Integer: %d\n", returnlen);
	returnlen = printf("Integer: %i\n", 3000);
	printf("Len Integer: %d\n", returnlen);
	
	printf("------------------------\n");	
	
	returnlen = ft_printf("Unsigned Int: %u\n", 4294967295);
	printf("Len Unsigned Int: %d\n", returnlen);
	returnlen = printf("Unsigned Int: %lu\n", 4294967295);
	printf("Len Unsigned Int: %d\n", returnlen);
	
	printf("------------------------\n");	
	
	returnlen = ft_printf("Hexadecimal X: %X\n", 0);
	printf("Len Hexadecimal: %d\n", returnlen);
	returnlen = printf("Hexadecimal X: %X\n", 0);
	printf("Len Hexadecimal: %d\n", returnlen);
	
	printf("------------------------\n");	
	
	returnlen = ft_printf("Hexadecimal x: %x\n", 2022);
	printf("Len hexadecimal: %d\n", returnlen);
	returnlen = printf("Hexadecimal x: %x\n", 2022);
	printf("Len hexadecimal: %d\n", returnlen);
	
	printf("------------------------\n");	
	returnlen = ft_printf("%%%%%%%%%%\n");
	printf("Len Percent: %d\n", returnlen);
	returnlen = printf("%%%%%%%%%%\n");
	printf("Len Percent: %d\n", returnlen);
	
	printf("------------------------\n");	
	returnlen = ft_printf("%s", "oi");
	printf("Len Percent: %d\n", returnlen);
	returnlen = printf("%s", "oi");
	printf("Len Percent: %d\n", returnlen);
}
*/
