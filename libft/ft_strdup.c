/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:56:54 by evdos-sa          #+#    #+#             */
/*   Updated: 2022/11/18 20:54:06 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* cria uma duplicata da string apontada por s e retorna um ponteiro à 
nova cópia.  */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*dst;

	dst = (char *)malloc(sizeof(const char) * ft_strlen(s) + 1);
	if (!dst)
		return (NULL);
	if (s)
		ft_memmove (dst, s, ft_strlen(s) + 1);
	else
		return (NULL);
	return (dst);
}
/*
int main()
{
    char source[] = "Geeks";
 
    // A copy of source is created dynamically
    // and pointer to copy is returned.
    //Uma cópia da fonte é criada dinamicamente
    // e o ponteiro para copiar é retornado.
    char* target = ft_strdup(source);
 
    printf("%s", target);
    return 0;
}
*/
