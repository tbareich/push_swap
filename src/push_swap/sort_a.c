/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 02:16:21 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/22 18:19:36 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	sort_a_three_helper(t_data *data, int right, int need_sa,
				int need_sort_two)
{
	if (need_sa)
		run_action(data, sa, 1);
	if (need_sort_two)
	{
		run_action(data, pb, 1);
		sort_a_two(data, right);
		run_action(data, pa, 1);
	}
}

static void	sort_non_sorted(t_data *data, int *idx, int left, int right)
{
	if (data->stack_a->array[idx[0]].value == left)
	{
		move_to_top(data, 'a', idx[0]);
		return (sort_a_three_helper(data, right, 0, 1));
	}
	move_to_top(data, 'a', idx[2]);
	if (data->stack_a->array[data->stack_a->top - 2].value == left
		&& data->stack_a->array[data->stack_a->top - 3].value == right)
		return (sort_a_three_helper(data, right, 1, 0));
	if (data->stack_a->array[data->stack_a->top - 2].value == left
		&& data->stack_a->array[data->stack_a->top - 1].value == right)
		return (sort_a_three_helper(data, right, 1, 1));
	if (data->stack_a->array[data->stack_a->top - 1].value == left)
		return (sort_a_three_helper(data, right, 0, 1));
}

void	sort_a_two(t_data *data, int right)
{
	t_stack	*stack;
	int		top;

	stack = data->stack_a;
	top = stack->top;
	if (stack->array[0].value <= right)
		run_action(data, rra, 1);
	if (stack->array[0].value <= right)
		run_action(data, rra, 1);
	if (stack->array[top - 1].value > stack->array[top - 2].value)
		run_action(data, sa, 1);
}

void	sort_a_three(t_data *data, int left, int right)
{
	t_stack	*stack;
	int		min_index;
	int		i;
	int		*idx;

	stack = data->stack_a;
	min_index = 0;
	i = stack->top - 1;
	while (i >= 0 && ft_between(stack->array[i].value, left, right))
	{
		min_index = i;
		--i;
	}
	idx = (int [3]){min_index,
		(min_index + 1) % stack->top, (min_index + 2) % stack->top};
	if (stack->array[idx[0]].value > stack->array[idx[1]].value
		&& stack->array[idx[1]].value > stack->array[idx[2]].value)
		return (move_to_top(data, 'a', idx[2]));
	sort_non_sorted(data, idx, left, right);
}
