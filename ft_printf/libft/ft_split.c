/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:42:09 by evdos-sa          #+#    #+#             */
/*   Updated: 2022/11/22 20:27:26 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parâmetros
	s: A string a ser dividida.
	c: O caractere delimitador.

Valor de retorno:
	A matriz de novas strings resultantes da divisão.
	NULL se a alocação falhar.

Funções externas:
	malloc, free.

Descrição:
	Aloca (com malloc(3)) e retorna um array de strings obtidas pela divisão 
	de 's' usando o método caractere 'c' como um delimitador.
	A matriz deve terminar com um ponteiro NULL.
*/
/* 1st: Saber quantas paravras existem na string original (s1) do split. */
/* 2nd: Saber quantas letras existem em cada palavra encontrada. */
/* 3th: Saber quais sao as palavras separadas. */
#include "libft.h"

/* 1st: Saber quantas paravras existem na string original (s1) do split. */
static int	count_strs(char const *cstr, char ch)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (cstr[i] != '\0')
	{
		while (cstr[i] == ch)
			i++;
		if (cstr[i] != '\0')
		{
			count++;
			while (cstr[i] != ch && cstr[i] != '\0')
				i++;
		}
	}
	return (count);
}

/* 2nd: Saber quantas letras existem em cada palavra encontrada. */
static int	count_chr(char const *schr, char c, int i)
{
	int	num_chr;

	num_chr = 0;
	while (schr[i] && schr[i] != c)
	{
		num_chr++;
		i++;
	}
	return (num_chr);
}

/* 3th: Saber quais sao as palavras separadas. */
char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**str;

	if (!s)
		return (NULL);
	i = 0;
	j = -1;
	str = (char **)malloc((count_strs(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (++j < count_strs(s, c))
	{
		while (s[i] == c)
			i++;
		str[j] = ft_substr(s, i, count_chr(s, c, i));
		if (!str)
			return (NULL);
		i += count_chr(s, c, i);
	}
	str[j] = 0;
	return (str);
}
/*
int        main(void)
{
    int i = 0;
    char **tab;
    char delim = '.';
        
    tab = ft_split("Ev.er.ton", delim);
    while (i < 4)
    {
        printf("string %d : %s\n", i, tab[i]);
        i++;
    }
    return (0);
}
	
	int	num = count_strs(string, ch);
	
	printf("%d\n", num);
	
	num_chr = count_chr(string);
	
	printf("%d\n", num_chr);
	return (0);
}
*/