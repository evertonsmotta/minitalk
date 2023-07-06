/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:58:11 by evdos-sa          #+#    #+#             */
/*   Updated: 2022/11/19 17:18:20 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Esta função retorna um ponteiro para a última ocorrência do caractere em s.*/
/*Se o valor não for encontrado, a função retornará um ponteiro nulo.*/

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	if (c == '\0')
		return ((char *)str + i);
	while (i >= 0)
	{
		if (str[i] == c)
			return ((char *)str + i);
		i--;
	}
	return (NULL);
}
/*
int main ()
{
   const char str[] = "Everton.S. Mota";
   const char ch = '.';
   char *ret;

   ret = ft_strrchr(str, ch);

   printf("%s\n", ret);
   
   ret = strrchr(str, ch);
   
   printf("%s\n", ret);
   
   return(0);
}
*/