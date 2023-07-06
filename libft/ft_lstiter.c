/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:21:09 by evdos-sa          #+#    #+#             */
/*   Updated: 2022/11/26 16:32:48 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parâmetros:
	lst: O endereço de um ponteiro para um nó.
	f: O endereço da função usada para iterar em a lista.
Valor de retorno: Nenhum
Funções externas:  Nenhum
Descrição:
	Itera a lista 'lst' e aplica a função 'f' no conteúdo de cada nó.
*/
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f (lst->content);
		lst = lst->next;
	}
}
