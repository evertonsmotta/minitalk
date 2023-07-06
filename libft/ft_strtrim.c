/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:45:23 by evdos-sa          #+#    #+#             */
/*   Updated: 2022/11/21 21:46:51 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Aloca (com malloc(3)) e retorna uma cópia de 's1' com os caracteres        */
/* especificados em 'set' removidos desde o início e o fim da string          */
/* s1: A string a ser aparada.                                                */
/* set: O conjunto de referência de caracteres a serem cortados.              */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1[j - 1] && ft_strrchr(set, s1[j - 1]) && j > i)
		j--;
	res = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, &s1[i], j - i + 1);
	return (res);
}
