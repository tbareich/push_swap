/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 04:00:30 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/14 21:27:14 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	sort_tree(t_turn *turn)
{
	int	*array;

	array = turn->stack_a->array;
	if (array[0] > array[1] && array[1] < array[2] && array[2] < array[0])
		run_action(turn, sa, 1);
	if (array[0] < array[1] && array[1] < array[2])
	{	
		run_action(turn, sa, 1);
		run_action(turn, rra, 1);
	}
	if (array[0] > array[1] && array[1] < array[2] && array[2] > array[0])
		run_action(turn, ra, 1);
	if (array[0] < array[1] && array[1] > array[2] && array[2] < array[0])
	{	
		run_action(turn, sa, 1);
		run_action(turn, ra, 1);
	}
	if (array[0] < array[1] && array[1] > array[2] && array[2] > array[0])
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
				turn->stack_b->array[turn->stack_b->top - 1]))
		{
			index = find_min(turn->stack_a);
			if (index != -1)
				move_to_top(turn, 'a', index);
		}
		else
			find_middle_spot_a(turn, turn->stack_a,
				turn->stack_b->array[turn->stack_b->top - 1]);
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
