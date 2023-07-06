/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:51:04 by evdos-sa          #+#    #+#             */
/*   Updated: 2022/11/26 11:42:55 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parâmetros
	s: A string na qual iterar.
	f: A função a ser aplicada a cada caractere.

Valor de retorno: Nenhum
Funções externas:  Nenhum

Descrição:
	Aplica a função 'f' em cada caractere de a string passada como argumento, 
	passando seu índice como primeiro argumento.  Cada personagem é passado 
	por endereço para 'f' para ser modificado se necessário.
*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
	s[i] = '\0';
}
/*
char	f(unsigned int i, char c)
{
	char	str;

	str = c + i;
	return (str);
}

int		main(int argc, const char *argv[])
{
	char	*str;

	alarm(5);
	str = (char *)malloc(sizeof(*str) * 12);
	if (argc == 1 || !str)
		return (0);
	else if (atoi(argv[1]) == 1)
	{
		strcpy(str, "LoReM iPsUm");
		ft_striteri(str, &iter);
		ft_print_result(str);
	}
	return (0);
}*/