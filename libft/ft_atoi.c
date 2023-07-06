/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:38:27 by evdos-sa          #+#    #+#             */
/*   Updated: 2022/11/20 14:39:53 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  converte o argumento de string str em um inteiro (tipo int).*/
#include "libft.h"

int	ft_atoi(char *str)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	j = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			j = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * j);
}
/*
#include <stdio.h>

int 	main(void)
{
	int result;

	result = ft_atoi(" 		--++-12Z1");
	printf("%d\n", result);
	return (0);
}*/
