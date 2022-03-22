/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 01:57:07 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/22 18:19:45 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	sort_b_two(t_data *data)
{
	t_stack	*stack;
	int		i;
	int		top;

	stack = data->stack_b;
	top = stack->top;
	i = 0;
	while (i < 2 && stack->top > 0)
	{
		top = stack->top;
		if (stack->array[0].value > stack->array[top - 1].value)
			run_action(data, rrb, 1);
		if (stack->array[0].value > stack->array[top - 1].value)
			run_action(data, rrb, 1);
		if (stack->array[top - 1 - !!(top - 1)].value
			> stack->array[top - 1].value)
			run_action(data, sb, 1);
		run_action(data, pa, 1);
		++i;
	}
}

static void	sort_b_three_fix(t_data *data, int left, int right, int dist)
{
	t_stack	*stack;
	int		top;

	stack = data->stack_b;
	top = stack->top;
	if (stack->array[0].value == right)
		run_action(data, rrb, 1);
	if (stack->array[1].value == right)
		run_action(data, sb, 1);
	run_action(data, pa, 1);
	sort_b(data, left, right - 1, dist - 1);
}

void	sort_b_three(t_data *data, int left, int right, int dist)
{
	t_stack	*stack;
	int		top;

	stack = data->stack_b;
	top = stack->top;
	if (stack->array[top - 3].value == right)
		run_action(data, rb, 1);
	if (stack->array[top - 2].value == right)
		run_action(data, sb, 1);
	while (stack->array[0].value == right || stack->array[1].value == right
		|| stack->array[2].value == right)
		run_action(data, rrb, 1);
	run_action(data, pa, 1);
	sort_b(data, left, right - 1, dist - 1);
}

void	sort_b(t_data *data, int left, int right, int dist)
{
	t_stack	*stack;
	int		i;
	int		top;

	stack = data->stack_b;
	top = stack->top;
	i = 0;
	if (dist == 1)
		sort_b_two(data);
	else if (dist == 2 && top == 3)
		sort_b_three_fix(data, left, right, dist);
	else if (top > 3)
		sort_b_three(data, left, right, dist);
}
