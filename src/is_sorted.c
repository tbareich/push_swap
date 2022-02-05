/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 21:18:55 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/05 21:26:16 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

char	is_sorted(t_turn turn)
{
	t_stack_element *current;

	if (turn.stack_b->top != NULL)
		return (0);
	current = turn.stack_a->top;
	while (current->prev)
	{
		if (current->value > current->prev->value)
			return (0);
		current = current->prev;
	}
	return (1);
}
