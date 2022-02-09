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
	add_action_list(&(turn->a_actions->head), pb);
	run_action(turn, pb, 0);
	print_lst_actions(turn);
}

void	sort_by_chanks(t_turn *turn, int length)
{
	int		index;
	int		i;

	i = 0;
	while (turn->stack_a->top)
	{
		if (i >= turn->low_min && i < turn->low_max)
			index = search_in_range(turn, 0, length / 2);
		else if (i >= turn->up_min && i < turn->up_max)
			index = search_in_range(turn, length / 2, length);
		else
			index = search_in_range(turn, 0, length);
		place_in_best_position(turn, index);
		++i;
	}
	index = find_max(turn->stack_b);
	if (index != -1)
		move_to_top(turn, 'b', index);
}
