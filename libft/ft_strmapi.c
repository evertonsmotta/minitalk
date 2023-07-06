/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:48:10 by evdos-sa          #+#    #+#             */
/*   Updated: 2022/11/26 11:22:32 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Description:
	Aplica a função 'f' a cada caractere do string 's', e passando seu índice 
como primeiro argumento para criar uma nova string (com malloc(3)) resultante
 de aplicações sucessivas de 'f'. 
Parameters:
	s: A string na qual iterar.
	f: A função a ser aplicada a cada caractere.
Return:
	A string criada a partir da aplicacao sucessiva de 'f'.
	Retorna NULL se a alocação falhar.

 Resumo:
	
*/
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	if (!s || !f)
		return (NULL);
	str = (char *)malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
char f(unsigned int i, char c)
{
    char str;
    str = c + i;
    return (str);
}

int main()
{
    char str1[] = "abc";
    char* str2;
    str2 = ft_strmapi(str1, *f);
    printf("%s\n", str2);
}*/