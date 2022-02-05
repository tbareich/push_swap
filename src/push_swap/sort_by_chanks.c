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

static void	place_in_best_position(t_turn *turn, t_stack_element *element)
{
	t_stack_element *founded_element;

	if (element)
		move_to_top_a_optimized(turn, get_index(*(turn->stack_a), *element));
	if (is_min_max(turn->stack_b,
			*(turn->stack_a->top)))
	{
		founded_element = find_max(turn->stack_b);
		if (founded_element != NULL)
			move_to_top_b_optimized(turn, 
					get_index(*(turn->stack_b), *founded_element));
	}
	else
		find_middle_spot_b(turn, turn->stack_b,
			turn->stack_a->top->value);
	add_action(&(turn->a_actions->head), pb);
	run_action(turn, pb, 0);
	print_lst_actions(turn);
}

void	sort_by_chanks(t_turn *turn, int length)
{
	t_stack_element	*element;
	int		i;

	i = 0;
	while (turn->stack_a->top)
	{
		if (i >= turn->low_min && i < turn->low_max)
			element = search_in_range(turn, 0, length / 2);
		else if (i >= turn->up_min && i < turn->up_max)
			element = search_in_range(turn, length / 2, length);
		else
			element = search_in_range(turn, 0, length);
		if (element != NULL)
			place_in_best_position(turn, element);
		++i;
	}
	element = find_max(turn->stack_b);

	if (element)
		move_to_top(turn, 'b', get_index(*(turn->stack_b), *element));	
}
