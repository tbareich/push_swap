/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 04:00:30 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/22 18:19:26 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	sort_tree(t_data *data)
{
	t_stack_element	*array;

	array = data->stack_a->array;
	if (array[0].value > array[1].value && array[1].value
		< array[2].value && array[2].value < array[0].value)
		run_action(data, sa, 1);
	if (array[0].value < array[1].value && array[1].value
		< array[2].value)
	{	
		run_action(data, sa, 1);
		run_action(data, rra, 1);
	}
	if (array[0].value > array[1].value && array[1].value
		< array[2].value && array[2].value > array[0].value)
		run_action(data, ra, 1);
	if (array[0].value < array[1].value && array[1].value
		> array[2].value && array[2].value < array[0].value)
	{	
		run_action(data, sa, 1);
		run_action(data, ra, 1);
	}
	if (array[0].value < array[1].value && array[1].value
		> array[2].value && array[2].value > array[0].value)
		run_action(data, rra, 1);
}

static void	sort_four_and_five(t_data *data)
{
	int	index;

	if (data->stack_a->top == 5)
		run_action(data, pb, 1);
	run_action(data, pb, 1);
	sort_tree(data);
	while (data->stack_b->top)
	{
		if (is_min_max(data->stack_a,
				data->stack_b->array[data->stack_b->top - 1].value))
			index = find_min(data->stack_a);
		else
			index = find_middle_spot_a(data->stack_a,
					data->stack_b->array[data->stack_b->top - 1].value);
		if (index != -1)
			move_to_top(data, 'a', index);
		run_action(data, pa, 1);
	}
	index = find_min(data->stack_a);
	if (index != -1)
		move_to_top(data, 'a', index);
}

void	simple_sort(t_data *data)
{
	if (data->stack_a->top == 2)
		run_action(data, sa, 1);
	if (data->stack_a->top == 3)
		sort_tree(data);
	if (data->stack_a->top >= 4)
		sort_four_and_five(data);
}
