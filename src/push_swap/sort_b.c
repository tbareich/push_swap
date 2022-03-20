/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 01:57:07 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/20 02:32:33 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	sort_b_two(t_turn *turn)
{
	t_stack	*stack;
	int		i;
	int		top;

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

static void	sort_b_three_fix(t_turn *turn, int left, int right, int dist)
{
	t_stack	*stack;
	int		top;

	stack = turn->stack_b;
	top = stack->top;
	if (stack->array[0].value == right)
		run_action(turn, rrb, 1);
	if (stack->array[1].value == right)
		run_action(turn, sb, 1);
	run_action(turn, pa, 1);
	sort_b(turn, left, right - 1, dist - 1);
}

void	sort_b_three(t_turn *turn, int left, int right, int dist)
{
	t_stack	*stack;
	int		top;

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

void	sort_b(t_turn *turn, int left, int right, int dist)
{
	t_stack	*stack;
	int		i;
	int		top;

	stack = turn->stack_b;
	top = stack->top;
	i = 0;
	if (dist == 1)
		sort_b_two(turn);
	else if (dist == 2 && top == 3)
		sort_b_three_fix(turn, left, right, dist);
	else if (top > 3)
		sort_b_three(turn, left, right, dist);
}
