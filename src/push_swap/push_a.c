/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:38:33 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/18 22:41:38 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void sort_two(t_turn *turn, int left, int right, int dist)
{
	t_stack *stack;
	int		i;
	int 	top;

	stack = turn->stack_b;
	top = stack->top;
	i = 0;
	while (i < 2 && stack->top > 0)
	{
		top = stack->top;
		if (stack->array[0].value > stack->array[top - 1].value)
			run_action(turn, rrb, 1);
		if (stack->array[0].value > stack->array[top - 1].value)
			run_action(turn, rrb, 1);
		if (stack->array[top - 1 - !!(top - 1)].value
					> stack->array[top - 1].value)
			run_action(turn, sb, 1);
		run_action(turn, pa, 1);
		++i;
	}
}

static void sort_three(t_turn *turn, int left, int right, int dist)
{
	t_stack *stack;
	int 	top;

	stack = turn->stack_b;
	top = stack->top;
	if (stack->array[0].value == right)
		run_action(turn, rrb, 1);
	if (stack->array[1].value == right)
		run_action(turn, sb, 1);
	run_action(turn, pa, 1);
	sort_b(turn, left, right - 1, dist - 1);
}

void sort_b (t_turn *turn, int left, int right, int dist)
{
	t_stack *stack;
	int		i;
	int 	top;

	stack = turn->stack_b;
	top = stack->top;
	while (stack->array[top - 1].value < left && stack->array[0].value < left)
		run_action(turn, rrb, 1);
	i = 0;
	if (dist == 1 && top > 0)
		sort_two(turn, left, right, dist);
	else if (dist == 2 && top == 3)
		sort_three(turn, left, right, dist);
	else if (top > 3)
		sort_b_two_elements(turn, left, right, dist);
}

void sort_b_two_elements(t_turn *turn, int left, int right, int dist)
{
	t_stack *stack;
	int		i;
	int 	top;

	stack = turn->stack_b;
	top = stack->top;
	if (stack->array[top - 3].value == right)
		run_action(turn, rb, 1);
	if (stack->array[top - 2].value == right)
		run_action(turn, sb, 1);
	while (stack->array[0].value == right || stack->array[1].value == right
			|| stack->array[2].value == right)
		run_action(turn, rrb, 1);
	run_action(turn, pa, 1);
	sort_b(turn, left, right - 1, dist - 1);
}

void	push_a(t_turn *turn, int left, int right)
{
	int	mid;
	int	dist;
	int i;
	int	down;
	int index;

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
	if (dist < 3)
	{
		// if (dist == 2)
		// 	sort_three(turn, left, right);
		// else if (dist == 1)
		// 	sort_two(turn, left, right);
		// else
		// {
		// 	if (ft_between(turn->stack_b->array[0].value, left, right))
		// 		move_to_top(turn, 'b', 0);
		// 	run_action(turn, pa, 1);
		// }
		sort_b(turn, left, right, dist);
		return ;
	}
	mid = left + dist / 2 + dist % 2;
	i = 0;
	down = 0;
	while (i < ((dist + 1) / 2 + (dist + 1) % 2))
	{
		index = search_in_range(turn->stack_b, mid, right);
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