/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 06:59:53 by tbareich          #+#    #+#             */
/*   Updated: 2022/01/11 08:33:17 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	add_action(t_list **actions_list, e_operation operation)
{
	t_list		*node;

	node = ft_lstnew(&operation, sizeof(e_operation));
	if (node == NULL)
		error(MEMOERROR);
	ft_lstpush(actions_list, node);
}