/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:57:17 by evdos-sa          #+#    #+#             */
/*   Updated: 2022/11/19 18:06:23 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	if (!dst && !src)
		return (0);
	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	dst_len = ft_strlen(dst);
	i = 0;
	while (src[i] != '\0' && dst_len + 1 < size)
	{
		dst[dst_len] = src[i];
		dst_len++;
		i++;
	}
	dst[dst_len] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}
/*
#include <string.h>
#include <stdio.h>

int main(void)
{
    char src[] = "plays";
    char dest[50] = "rrrrrrrrrrrrrrr";
    
    printf("%ld\n", ft_strlcat(dest, src, 16));
    printf("%s\n", dest);
    printf("\n");
    
    char src1[] = "plays";
    char dest1[16] = "juninho ";
    
    printf("%ld\n", ft_strlcat(dest1, src1, 0));
    printf("%s\n", dest1);
    printf("\n");
    
    char src2[] = "plays";
    char dest2[16] = "juninho ";
    
    printf("%ld\n", ft_strlcat(dest2, src2, 13));
    printf("%s\n", dest2);
    printf("\n");
    
    char src3[] = "plays";
    char dest3[16] = "juninho ";
    
    printf("%ld\n", ft_strlcat(dest3, src3, 1));
    printf("%s\n", dest3);
    printf("\n");
    
    return (0);
}
*/