/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:16:51 by evdos-sa          #+#    #+#             */
/*   Updated: 2022/11/26 15:38:00 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters:
	lst: O endereço de um ponteiro para o primeiro link de uma lista.
	new: O endereço de um ponteiro para o nó a ser adicionado à lista.
Return value: None
External functs: None
Description:
	Adiciona o nó 'new' no final da lista.
*/
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	p = ft_lstlast(*lst);
	p -> next = new;
}
