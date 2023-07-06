/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:47:21 by evdos-sa          #+#    #+#             */
/*   Updated: 2022/11/26 14:09:44 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parâmetros:
	content: O conteúdo com o qual criar o nó.
Valor de retorno:
	O novo nó
Funções externas:
	malloc
Descrição:
	Aloca (com malloc(3)) e retorna um novo nó.
	A variável de membro 'content' é inicializada com o valor do parâmetro 
	'conteúdo'.  a variável 'próximo' é inicializado como NULL.
*/
/*
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
*/
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node -> content = content;
	node -> next = NULL;
	return (node);
}
