/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:33:34 by evdos-sa          #+#    #+#             */
/*   Updated: 2022/11/26 17:07:57 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parâmetros:
	lst: O endereço de um ponteiro para um nó.
	f: O endereço da função usada para iterar em a lista.
	del: O endereço da função usada para excluir o conteúdo de um nó, se 
	necessário.
Valor de retorno:
	A nova lista.
	NULL se a alocação falhar.
Funções externas:
	malloc, free
Descrição:
	Itera a lista 'lst' e aplica a função 'f' no conteúdo de cada nó.
	Cria uma nova lista resultante das sucessivas aplicações de a função 'f'. 
	A função 'del' é usada para exclua o conteúdo de um nó, se necessário.
*/
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*node;

	if (!lst || !f || !del)
		return (NULL);
	newlist = 0;
	while (lst)
	{
		node = ft_lstnew (f(lst -> content));
		if (!node)
		{
			ft_lstclear (&newlist, del);
			return (0);
		}
		ft_lstadd_back(&newlist, node);
		lst = lst -> next;
	}
	return (newlist);
}
