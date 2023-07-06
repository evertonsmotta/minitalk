/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:18:39 by evdos-sa          #+#    #+#             */
/*   Updated: 2022/11/26 15:34:39 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parâmetros:
	lst: O endereço de um ponteiro para o primeiro link de uma lista.
	new: O endereço de um ponteiro para o nó a ser adicionado à lista.
Valor de retorno: Nenhum
Funções externas: Nenhum
Descrição:
	Adiciona o nó 'new' no início da lista.
*/
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new -> next = *lst;
		*lst = new;
	}
}
