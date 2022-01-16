/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_chanks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 01:54:03 by tbareich          #+#    #+#             */
/*   Updated: 2022/01/07 08:15:10 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	place_in_best_position(t_turn *turn, int index)
{
	move_to_top_a_optimized(turn, index);
	if (is_min_max(turn->stack_b,
			turn->stack_a->array[turn->stack_a->top - 1]))
	{
		index = find_max(turn->stack_b);
		if (index != -1)
			move_to_top_b_optimized(turn, index);
	}
	else
		find_middle_spot_b(turn, turn->stack_b,
			turn->stack_a->array[turn->stack_a->top - 1]);
	add_action(&(turn->a_actions), pb);
	run_action(turn, pb, 0);
	print_lst_actions(turn);
}

void	sort_by_chanks(t_turn *turn, int divider, int length)
{
	int		chank;
	int		index;
	int		step;

	chank = length / divider;
	step = chank;
	while (turn->stack_a->top)
	{
		index = search_in_range(turn, chank);
		if (index == -1)
		{
			chank += step;
			continue ;
		}
		place_in_best_position(turn, index);
	}
	index = find_max(turn->stack_b);
	if (index != -1)
		move_to_top(turn, 'b', index);
}
