/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:47:46 by evdos-sa          #+#    #+#             */
/*   Updated: 2022/11/26 14:59:14 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parâmetros:
	lst: O início da lista.
Valor de retorno:
	O comprimento da lista
Funções externas:
	Nenhum
Descrição:
	Conta o número de nós em uma lista.
*/
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}
