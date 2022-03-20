/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:57:08 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/20 02:28:01 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	push_b_elements(t_turn *turn, int left, int right)
{
	int	mid;
	int	i;
	int	down;
	int	dist;

	dist = right - left;
	mid = left + dist / 2 + dist % 2 ;
	i = 0;
	down = 0;
	while (i < ((dist + 1) / 2))
	{
		if (turn->stack_a->array[turn->stack_a->top - 1].value > right)
			down = 1;
		if (turn->stack_a->array[turn->stack_a->top - 1].value < mid)
		{
			run_action(turn, pb, 1);
			++i;
		}
		else if (turn->stack_a->array[0].value < mid || down)
			run_action(turn, rra, 1);
		else if (turn->stack_a->array[turn->stack_a->top - 1].value >= mid)
			run_action(turn, ra, 1);
	}
	return (mid);
}

void	push_b(t_turn *turn, int left, int right)
{
	int	mid;
	int	dist;

	if (is_sorted_dir_a(turn, left, right, -1))
		return ;
	dist = right - left;
	if (dist < 3)
	{
		if (dist == 2)
			sort_a_three(turn, left, right);
		else if (dist == 1)
			sort_a_two(turn, right);
		return ;
	}
	mid = push_b_elements(turn, left, right);
	push_b(turn, mid, right);
	push_a(turn, left, mid - 1);
}
