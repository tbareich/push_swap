/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:38:33 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/16 22:17:48 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	sort_two(t_turn *turn, int left, int right)
{
	int		top;
	t_stack *stack;
	int i = 0;

	if (turn->stack_b->array[0].value == left)
		move_to_top(turn, 'b', 0);
	if (turn->stack_b->array[0].value == right)
		move_to_top(turn, 'b', 0);
	if (turn->stack_b->array[turn->stack_b->top-2].value == right)
		run_action(turn, sb, 1);
	run_action(turn, pa, 1);
	if (turn->stack_b->array[0].value == left)
		move_to_top(turn, 'b', 0);
	run_action(turn, pa, 1);
}


static void sort_three(t_turn *turn, int left, int right)
{
	int 	min_index;
	int		i;
	t_stack	*stack;
	int		*idx;

	stack = turn->stack_b;
	min_index = 0;
	i = stack->top - 1;
	while (i >= 0 && ft_between(stack->array[i].value, left, right))
	{
		min_index = i;
		--i;
	}
	idx = (int[3]){min_index,
				(min_index + 1) % stack->top, (min_index + 2) % stack->top};
	if (stack->array[idx[0]].value < stack->array[idx[1]].value
		&& stack->array[idx[1]].value < stack->array[idx[2]].value)
	{
		move_to_top(turn, 'b', idx[2]);
		run_action(turn, pa, 1);
		run_action(turn, pa, 1);
		run_action(turn, pa, 1);
		return ;
	}
	if (stack->array[idx[0]].value == right)
	{
		move_to_top(turn, 'b', idx[0]);
		run_action(turn, pa, 1);
		sort_two(turn, left, right - 1);
		return ;
	}
	if (stack->array[idx[1]].value == right
		&& stack->array[idx[0]].value == right - 1)
	{
		move_to_top(turn, 'b', idx[1]);
		run_action(turn, pa, 1);
		sort_two(turn, left, right - 1);
		return ;
	}
	if (stack->array[idx[0]].value == right - 1
		&& stack->array[idx[1]].value == left)
	{
		move_to_top(turn, 'b', idx[2]);
		run_action(turn, pa, 1);
		sort_two(turn, left, right - 1);
		return ;
	}
	move_to_top(turn, 'b', idx[2]);
	run_action(turn, sb, 1);
	run_action(turn, pa, 1);
	run_action(turn, pa, 1);
	run_action(turn, pa, 1);
}

void	push_a(t_turn *turn, int left, int right)
{
	int	mid;
	int	dist;
	int i;
	int	down;

	dist = right - left;
	if (is_sorted_dir(turn, turn->stack_b, 'b', left, right, 1))
	{
		while (dist > -1)
		{
			run_action(turn, pa, 1);
			--dist;
		}
		return ;
	}
	if (dist < 2)
	{
		if (dist == 1)
			sort_two(turn, left, right);
		else
		{
			if (ft_between(turn->stack_b->array[0].value, left, right))
				move_to_top(turn, 'b', 0);
			run_action(turn, pa, 1);
		}
		return ;
	}
	mid = left + dist / 2 + dist % 2;
	i = 0;
	down = 0;
	while (i < ((dist + 1) / 2 + (dist + 1) % 2))
	{

		down = turn->stack_b->array[turn->stack_b->top - 1].value < left
				|| down;
		if (turn->stack_b->array[0].value >= mid || down)
			run_action(turn, rrb, 1);
		else if (turn->stack_b->array[turn->stack_b->top - 1].value < mid)
			run_action(turn, rb, 1);
		if (turn->stack_b->array[turn->stack_b->top - 1].value >= mid)
		{
			run_action(turn, pa, 1);
			++i;
		}
	}
	push_b(turn,  mid, right);
	push_a(turn, left, mid - 1);
}