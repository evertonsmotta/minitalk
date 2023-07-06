/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isldigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:25:00 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/07/03 19:28:38 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_isldigit(long int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int main()
{
    char c;

    printf("Enter a character: ");
    scanf("%c",&c);

    if (ft_isdigit(c) == 0)
         printf("%c is not a digit.",c);
    else
         printf("%c is a digit.",c);

    if (isdigit(c) == 0)
         printf("%c is not a digit.",c);
    else
         printf("%c is a digit.",c);
    return 0;
}*/