/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:57:08 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/16 22:16:42 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	sort_two(t_turn *turn, int left, int right)
{
	int		top;
	t_stack *stack;
	int i = 0;

	while (i < 2)
	{
		if (ft_between(turn->stack_a->array[0].value, left, right))
			move_to_top(turn, 'a', 0);
		i++;
	}
	stack = turn->stack_a;
	top = stack->top;
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
			return ;
	if (stack->array[idx[0]].value == left)
	{
		move_to_top(turn, 'a', idx[0]);
		run_action(turn, pb, 1);
		sort_two(turn,
			left + 1, right);
		run_action(turn, pa, 1);
		return ;
	}
	if (stack->array[idx[1]].value == left
		&& stack->array[idx[0]].value == left + 1)
	{
		move_to_top(turn, 'a', idx[1]);
		run_action(turn, pb, 1);
		sort_two(turn, left + 1, right);
		run_action(turn, pa, 1);
		return ;
	}
	if (stack->array[idx[0]].value == left + 1
		&& stack->array[idx[1]].value == right)
	{
		if (idx[2] >= 3)
			run_action(turn, pb, 1);
		sort_two(turn, left + 1, right);
		if (idx[2] < 3)
			run_action(turn, rra, 1);
		else
			run_action(turn, pa, 1);		
		return ;
	}
	move_to_top(turn, 'a', idx[2]);
	run_action(turn, sa, 1);
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
	if (dist < 2)
	{
		if (dist == 1)
			sort_two(turn, left, right);
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