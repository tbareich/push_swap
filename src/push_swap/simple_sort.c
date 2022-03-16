/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 04:00:30 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/08 21:44:52 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	sort_tree(t_turn *turn)
{
	t_stack_element	*array;

	array = turn->stack_a->array;
	if (array[0].value > array[1].value && array[1].value
		< array[2].value && array[2].value < array[0].value)
		run_action(turn, sa, 1);
	if (array[0].value < array[1].value && array[1].value
		< array[2].value)
	{	
		run_action(turn, sa, 1);
		run_action(turn, rra, 1);
	}
	if (array[0].value > array[1].value && array[1].value
		< array[2].value && array[2].value > array[0].value)
		run_action(turn, ra, 1);
	if (array[0].value < array[1].value && array[1].value
		> array[2].value && array[2].value < array[0].value)
	{	
		run_action(turn, sa, 1);
		run_action(turn, ra, 1);
	}
	if (array[0].value < array[1].value && array[1].value
		> array[2].value && array[2].value > array[0].value)
		run_action(turn, rra, 1);
}

static void	sort_five(t_turn *turn)
{
	int	index;

	run_action(turn, pb, 1);
	run_action(turn, pb, 1);
	sort_tree(turn);
	while (turn->stack_b->top)
	{
		if (is_min_max(turn->stack_a,
				turn->stack_b->array[turn->stack_b->top - 1].value))
		{
			index = find_min(turn->stack_a);
			if (index != -1)
				move_to_top(turn, 'a', index);
		}
		else
		/// TODO: changed find middle need move top
			// find_middle_spot_a(turn->stack_a,
			// 	turn->stack_b->array[turn->stack_b->top - 1].value);
		run_action(turn, pa, 1);
	}
	index = find_min(turn->stack_a);
	if (index != -1)
		move_to_top(turn, 'a', index);
}

void	simple_sort(t_turn *turn)
{
	if (turn->stack_a->top == 2)
		run_action(turn, sa, 1);
	if (turn->stack_a->top == 3)
		sort_tree(turn);
	if (turn->stack_a->top == 5)
		sort_five(turn);
}
