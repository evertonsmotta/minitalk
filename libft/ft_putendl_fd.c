/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:09:51 by evdos-sa          #+#    #+#             */
/*   Updated: 2022/11/27 12:28:21 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parâmetros:
	s: A string para saída.
	fd: O descritor de arquivo no qual escrever.
Valor de retorno:
	Nenhum
Funções externas:
	Write
Descrição:
	Emite a string 's' para o descritor de arquivo fornecido seguido por 
	uma nova linha.
*/

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
		{
			ft_putchar_fd(*s, fd);
			s++;
		}
		ft_putchar_fd('\n', fd);
	}
}
/*
void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
		{
			ft_putchar_fd(*s, fd);
			s++;
		}
		ft_putchar_fd('\n', fd);
	}	
}
*/