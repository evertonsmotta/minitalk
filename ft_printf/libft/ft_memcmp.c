/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:55:56 by evdos-sa          #+#    #+#             */
/*   Updated: 2022/11/19 16:45:04 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Compara os primeiros n bytes da área de memória s1 e da área de memória s2.*/
/* if Return value < 0 then it indicates str1 is less than str2.*/
/* if Return value > 0 then it indicates str2 is less than str1.*/
/* if Return value = 0 then it indicates str1 is equal to str2.*/
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (0);
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
		{
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		}
		i++;
	}
	return (0);
}
/*
int main () {
   char strA[10];
   char strB[10];
   int ret;

   memcpy(strA, "abc", 4);
   memcpy(strB, "abca", 4);

   ret = ft_memcmp(strA, strB, 4);

   if(ret > 0) {
      printf("strB is less than strA");
   } else if(ret < 0) {
      printf("strA is less than strB");
   } else {
      printf("strA is equal to strB");
   }
   
   return(0);
}*/