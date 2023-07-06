/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:57:26 by evdos-sa          #+#    #+#             */
/*   Updated: 2022/11/19 17:34:19 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*A função strlcpy() copia até o tamanho − 1 caracteres da string terminada 
em NUL src para dst, terminando em NUL o resultado.*/
/*Para strlcpy() isso significa o comprimento de src.*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = ft_strlen(src);
	if (size < 1)
		return (j);
	i = 0;
	while (src[i] != '\0' && (i < size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}

/*

#include <stdio.h>
#include <string.h>

int main(void)//Retorno: 5
{
	char src[] = "Hello";
	char dest[10];
	printf("%ld\n", ft_strlcpy(dest, src, 0));
	printf("%s\n", dest);
}*/