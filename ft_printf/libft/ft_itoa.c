/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:36:08 by evdos-sa          #+#    #+#             */
/*   Updated: 2022/11/20 15:40:23 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	A função itoa() converte o inteiro n em uma string de caracteres.
	Aloca (com malloc(3)) e retorna uma string representando o inteiro recebido 
como um argumento. Números negativos devem ser tratados.
	Retorna um char. */
#include "libft.h"

static size_t	cont_digit(int n)
{
	size_t	cont;

	cont = 0;
	if (n <= 0)
		cont++;
	while (n != 0)
	{
		n = n / 10;
		cont++;
	}
	return (cont);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	cont;
	int		c;

	cont = cont_digit(n);
	str = malloc(sizeof(char) * (cont + 1));
	if (str == NULL)
		return (NULL);
	c = 1;
	str[cont] = '\0';
	cont--;
	if (n < 0)
	{
		str[0] = '-';
		c = -1;
	}
	else if (n == 0)
		str[cont] = '0';
	while (n != 0)
	{
		str[cont] = ((n % 10) * c) + 48;
		n = n / 10;
		cont--;
	}
	return (str);
}
/*
#include <limits.h>
#include <stdio.h>

char * ft_itoa(int n);

void check(int n) {
        printf("%i = %s\n", n, ft_itoa(n));
}

int main() {
        check(0);
		*/