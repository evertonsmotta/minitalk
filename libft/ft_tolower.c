/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:58:32 by evdos-sa          #+#    #+#             */
/*   Updated: 2022/11/18 21:14:27 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		c = c + 32;
	}
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>

int main ()
{
   int i = 0;
//   char c;
   char str[] = "EVERTON";
    
   while( str[i] )
   {
      putchar(ft_tolower(str[i]));
      i++;
   }
   
   return(0);
}*/	
