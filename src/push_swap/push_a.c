/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:38:33 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/20 02:17:32 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	push_a_elements(t_turn *turn, int left, int right)
{
	int	mid;
	int	i;
	int	down;
	int	up_mid_length;

	mid = left + (right - left) / 2 + (right - left) % 2;
	i = 0;
	down = 0;
	up_mid_length = right - mid + 1;
	while (i < up_mid_length)
	{
		if (turn->stack_b->array[turn->stack_b->top - 1].value < left)
			down = 1;
		if (turn->stack_b->array[turn->stack_b->top - 1].value >= mid)
		{
			run_action(turn, pa, 1);
			++i;
		}
		else if (turn->stack_b->array[0].value >= mid || down)
			run_action(turn, rrb, 1);
		else if (turn->stack_b->array[turn->stack_b->top - 1].value < mid)
			run_action(turn, rb, 1);
	}
	return (mid);
}

void	push_a(t_turn *turn, int left, int right)
{
	int	dist;
	int	mid;

	dist = right - left;
	if (is_sorted_dir_b(turn, left, right, 1))
	{
		while (dist-- > -1)
			run_action(turn, pa, 1);
		return ;
	}
	if (dist < 3)
		return (sort_b(turn, left, right, dist));
	mid = push_a_elements(turn, left, right);
	push_b(turn, mid, right);
	push_a(turn, left, mid - 1);
}
