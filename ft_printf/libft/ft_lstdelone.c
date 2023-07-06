/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:42:17 by evdos-sa          #+#    #+#             */
/*   Updated: 2022/11/26 16:09:51 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parâmetros:
	lst: O nó a ser liberado.
	del: O endereço da função usada para excluir o conteúdo.
Valor de retorno Nenhum
Funções externas: free
Descrição:
	Toma como parâmetro um node e libera (frees) a memória do conteúdo do nó 
	usando a função 'del' dada como parâmetro e libere (free) o nó.
	A memória de 'next' não deve ser liberado (freed).
*/
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del (lst -> content);
	free (lst);
}
