/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfhexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:27:32 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/01/21 12:31:07 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexanum(size_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_findhexa(size_t num, const char category)
{
	if (num >= 16)
	{
		ft_findhexa(num / 16, category);
		ft_findhexa(num % 16, category);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + 48), 1);
		else
		{
			if (category == 'x')
				ft_putchar_fd((num - 10 + 97), 1);
			if (category == 'X')
				ft_putchar_fd((num - 10 + 65), 1);
		}
	}
}

int	ft_printfhexa(size_t num, const char category)
{
	if (num != 0)
		ft_findhexa(num, category);
	else
		return (ft_putchar_fd('0', 1));
	return (ft_hexanum(num));
}

/*
MAIN

int main()
{
  int num = 11;
  char  format = 'X';
  ft_print_hex(num, format);

  return 0;
}
*/
