/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:58:42 by evdos-sa          #+#    #+#             */
/*   Updated: 2022/11/18 21:15:04 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		c = c - 32;
	}
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>

int main ()
{
   int i = 0;
   char str[] = "EverTON";
   
   while(str[i]) {
      putchar (toupper(str[i]));
      i++;
   }
   return(0);
}*/
