/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:57:08 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/19 05:29:03 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	sort_two(t_turn *turn, int right)
{
	int		top;
	t_stack *stack;

	stack = turn->stack_a;
	top = stack->top;
	if (stack->array[0].value <= right)
		run_action(turn, rra, 1);
	if (stack->array[0].value <= right)
		run_action(turn, rra, 1);
	if (stack->array[top - 1].value > stack->array[top - 2].value)
		run_action(turn, sa, 1);
}

static void sort_three(t_turn *turn, int left, int right)
{
	int 	min_index;
	int		i;
	t_stack	*stack;
	int		*idx;

	stack = turn->stack_a;
	min_index = 0;
	i = stack->top - 1;
	while (i >= 0 && ft_between(stack->array[i].value, left, right))
	{
		min_index = i;
		--i;
	}
	idx = (int[3]){min_index,
				(min_index + 1) % stack->top, (min_index + 2) % stack->top};
	if (stack->array[idx[0]].value > stack->array[idx[1]].value
		&& stack->array[idx[1]].value > stack->array[idx[2]].value)
	{
		move_to_top(turn, 'a', idx[2]);
		return ;
	}
	if (stack->array[idx[0]].value == left)
	{
		move_to_top(turn, 'a', idx[0]);
		run_action(turn, pb, 1);
		sort_two(turn, right);
		run_action(turn, pa, 1);
		return ;
	}
	if (stack->array[idx[1]].value == left
		&& stack->array[idx[0]].value == right)
	{
		move_to_top(turn, 'a', idx[2]);
		run_action(turn, sa, 1);
		return ;
	}
	if (stack->array[idx[1]].value == left
		&& stack->array[idx[2]].value == right)
	{
		move_to_top(turn, 'a', idx[2]);
		run_action(turn, sa, 1);
		run_action(turn, pb, 1);
		sort_two(turn, right);
		run_action(turn, pa, 1);
		return ;
	}
	if (stack->array[idx[2]].value == left)
	{
		move_to_top(turn, 'a', idx[2]);
		run_action(turn, pb, 1);
		sort_two(turn, right);
		run_action(turn, pa, 1);		
		return ;
	}
}

void	push_b(t_turn *turn, int left, int right)
{
	int	mid;
	int	dist;
	int i;
	int	down;
	
	if (is_sorted_dir(turn, turn->stack_a, 'a', left, right, -1))
		return ;
	dist = right - left;
	if (dist < 3)
	{
		if (dist == 2)
			sort_three(turn, left, right);
		else if (dist == 1)
			sort_two(turn, right);
		return ;
	}
	mid = left + dist / 2 + dist % 2 ;
	i = 0;
	down = 0;
	while (i < ((dist + 1) / 2))
	{

		down = turn->stack_a->array[turn->stack_a->top - 1].value > right
				|| down;
		if (turn->stack_a->array[0].value < mid || down)
			run_action(turn, rra, 1);
		else if (turn->stack_a->array[turn->stack_a->top - 1].value >= mid)
			run_action(turn, ra, 1);
		if (turn->stack_a->array[turn->stack_a->top - 1].value < mid)
		{
			run_action(turn, pb, 1);
			++i;
		}
	}
	push_b(turn, mid, right);
	push_a(turn, left, mid - 1);
}