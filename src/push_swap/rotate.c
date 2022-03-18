/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:52:40 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/17 18:45:39 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_operation	rotate_a(t_turn *turn, int left, int right, t_operation opt)
{
	int down;
	int	dist;
	int mid;

	dist = right - left;
	mid = left + dist / 2 + dist % 2;
	down = turn->stack_b->array[turn->stack_b->top - 1].value < left
				|| down;
	if ((turn->stack_b->array[0].value >= mid || down) && opt == rra)
		return (rrr);
	else if (turn->stack_b->array[turn->stack_b->top - 1].value < mid
				&& opt == ra)
			return (rr);
	else
		return (opt);
}

t_operation need_merge(t_turn *turn, t_operation operation)
{
	t_stack *stack_b;

	stack_b = turn->stack_b;
	if (stack_b->top > 1 && operation == rra
		&& stack_b->array[0].value > stack_b->array[stack_b->top - 1].value)
		return (rrr);
	if (stack_b->top > 1 && 
		operation == sa && stack_b->array[stack_b->top - 2].value 
		> stack_b->array[stack_b->top - 1].value)
		return (ss);
	return (operation);
}