/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:56:10 by evdos-sa          #+#    #+#             */
/*   Updated: 2022/11/19 15:58:09 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	size_t	j;

	if (!dest && !src)
		return (0);
	i = 0;
	j = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[j];
		i++;
		j++;
	}
	return (dest);
}
/*
int main () {
  const char src[10] = "E.Mota";
  char dest[10];
  strcpy(dest,"Heloooo!!");
  printf("Before memcpy dest = %s\n", dest);
  ft_memcpy(dest, src, strlen(src)+1);
  printf("After memcpy dest = %s\n", dest);
   
  return(0);
}
*/
