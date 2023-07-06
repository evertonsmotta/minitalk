/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:45:34 by evdos-sa          #+#    #+#             */
/*   Updated: 2022/11/26 12:41:06 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parâmetros:
	n: O inteiro para saída.
	fd: O descritor de arquivo no qual escrever.
Valor de retorno:
	Nenhum
Funções externas:
	Write.
Descrição:
	Envia o inteiro 'n' para o arquivo fornecido descritor.
*/

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd ("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd ('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n <= 9)
	{
		ft_putchar_fd (n + '0', fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd (n / 10, fd);
		ft_putchar_fd ((n % 10) + '0', fd);
	}
}
/*
int    main(void)
{
     ft_putnbr_fd(-2147483648, 2);
}
*/
