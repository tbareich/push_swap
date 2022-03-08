/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:38:33 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/08 00:29:41 by tbareich         ###   ########.fr       */
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

static void	sort_three(t_turn *turn, int left, int right)
{
	int		top;
	t_stack *stack;
	int i = 0;
	
	while (i < 3)
	{
		if (ft_between(turn->stack_b->array[0].value, left, right))
			move_to_top(turn, 'b', 0);
		i++;
	}
	stack = turn->stack_b;
	top = stack->top;
	if (stack->array[top - 1].value < stack->array[top - 2].value 
		&& stack->array[top - 1].value < stack->array[top - 3].value)
		run_action(turn, sb, 1);
	if (stack->array[top - 2].value < stack->array[top - 1].value
			&& stack->array[top - 2].value < stack->array[top - 3].value)
	{
		run_action(turn, rb, 1);
		run_action(turn, sb, 1);
		run_action(turn, rrb, 1);
	}
	if (stack->array[top - 1].value < stack->array[top - 2].value )
		run_action(turn, sb, 1);
}

void	push_a(t_turn *turn, int left, int right)
{
	int	mid;
	int	dist;
	int	index;
	int i = 0;

	dist = right - left;
	if (is_sorted_dir(turn, turn->stack_b, 'b', left, right, -1))
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
	index = 0;
	while (1)
	{
		index = search_in_range(turn->stack_b, mid, right);
		if (index == -1)
			break ;
		move_to_top(turn, 'b', index);
		run_action(turn, pa, 1);
	}
	push_b(turn,  mid, right);
	push_a(turn, left, mid - 1);
}