/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 21:18:55 by tbareich          #+#    #+#             */
/*   Updated: 2022/01/06 21:19:30 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

char	is_sorted(t_turn turn)
{
	int		i;

	if (turn.stack_b->top != 0)
		return (0);
	i = turn.stack_a->top - 1;
	while (i > 0)
	{
		if (turn.stack_a->array[i] > turn.stack_a->array[i - 1])
			return (0);
		--i;
	}
	return (1);
}
