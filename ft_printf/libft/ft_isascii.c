/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:54:50 by evdos-sa          #+#    #+#             */
/*   Updated: 2022/11/18 20:22:02 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
#include<stdio.h>
#include<ctype.h>
int	main()
{
  char val='7';

  if(ft_isascii(val))
    printf("This is ascii character \n");
   else
    printf("This is not ascii character \n");

  if(isascii(val))
    printf("This is ascii character \n");
   else
    printf("This is not ascii character \n");
  return 0;
}*/
