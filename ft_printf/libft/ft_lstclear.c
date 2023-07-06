/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:06:52 by evdos-sa          #+#    #+#             */
/*   Updated: 2022/11/26 16:19:41 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parâmetros:
	lst: O endereço de um ponteiro para um nó.
	del: O endereço da função usada para excluir o conteúdo do nó.
Valor de retorno: Nenhum.
Funções externas: free
Descrição:
	Exclui e libera o nó fornecido e cada sucessor desse nó, usando a função 
	'del' e free(3).
	Finalmente, o ponteiro para a lista deve ser definido como NULO.
*/
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*p;

	if (!lst || !del)
		return ;
	if (lst)
	{
		while (*lst)
		{
			p = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = p;
		}
	}
	*lst = NULL;
}
