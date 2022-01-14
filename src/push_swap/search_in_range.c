/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_in_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 02:25:54 by tbareich          #+#    #+#             */
/*   Updated: 2022/01/11 12:54:08 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		can_pushed_to_stack_b(t_stack *stack_b, int number)
{
	int		i;
	int		first_sign;
	int		tmp_sign;

	if (stack_b->top < 2)
		return (1);
	first_sign = number - stack_b->array[stack_b->top - 1];
	i = stack_b->top - 2;
	while (i >= 0)
	{
		tmp_sign = number - stack_b->array[i];
		if ((tmp_sign < 0 && first_sign >= 0) ||
				(tmp_sign >= 0 && first_sign < 0))
			return (0);
		--i;
	}
	return (1);
}

int		search_in_range(t_turn *turn, int chank)
{
	int		min_index;
	int		max_index;

	min_index = 0;
	max_index = turn->stack_a->top - 1;
	while (max_index >= min_index)
	{
		if (turn->stack_a->array[max_index] <= chank)
			return max_index;
		if (turn->stack_a->array[min_index] <= chank)
			return min_index;
		--max_index;
		++min_index;
	}
	return (-1);
}