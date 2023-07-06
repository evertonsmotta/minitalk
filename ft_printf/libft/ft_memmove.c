/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:56:18 by evdos-sa          #+#    #+#             */
/*   Updated: 2022/11/20 13:53:53 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;
	size_t	i;

	s = (char *)src;
	d = (char *)dst;
	if (!dst && !src)
		return (0);
	i = 0;
	if (d > s)
	{
		while (len-- > 0)
			d[len] = s[len];
	}
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
/*
int main ()
{
   char dest[] = "e.mota";
   const char src[]  = "E.Mota";
   
   char a[15];
   char b[] = "minha nossa";
   int n = 15;

   printf("Before memmove dest = %s, src = %s\n", dest, src);
   memmove(dest, src, sizeof(char) * 6);
   printf("After memmove dest = %s, src = %s\n\n", dest, src);
   
   printf("%s", ft_memmove(a, b, n));

   return(0);
}
*/
