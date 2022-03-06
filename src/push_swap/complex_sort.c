/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:19:45 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/05 16:43:39 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	run_and_add_action(t_turn *turn, t_list **action,
			t_operation operation, int index)
{
	while (index)
	{
		run_action(turn, operation, 0);
		add_action_list(action, operation);
		--index;
	}
}

void _push_a(t_turn *turn, int b_index, int a_index)
{
	int	l_ra_rb;
	int	l_ra_rrb;
	int l_rra_rb;
	int l_rra_rrb;

	l_ra_rb = max(turn->stack_a->top - 1 - a_index, 
					turn->stack_b->top - 1 - b_index);
	l_ra_rrb = turn->stack_a->top - 1 - a_index + b_index + 1;
	l_rra_rb = a_index + 1 + turn->stack_b->top - 1 - b_index;
	l_rra_rrb = max(b_index + 1, a_index + 1);
	if (l_ra_rb <= l_ra_rrb &&
		l_ra_rb <= l_rra_rb &&
		l_ra_rb <= l_rra_rrb)
	{
		run_and_add_action(turn, &(turn->b_actions->head), rb, turn->stack_b->top - 1 - b_index);
		run_and_add_action(turn, &(turn->a_actions->head), ra, turn->stack_a->top - 1 - a_index);
	}
	if (l_ra_rrb <= l_rra_rb &&
		l_ra_rrb <= l_rra_rrb)
	{
		run_and_add_action(turn, &(turn->b_actions->head), rrb, b_index + 1);
		run_and_add_action(turn, &(turn->a_actions->head), ra, turn->stack_a->top - 1 - a_index);
	}
	if (l_rra_rb <= l_rra_rrb)
	{
		run_and_add_action(turn, &(turn->b_actions->head), rb, turn->stack_b->top - 1 - b_index);
		run_and_add_action(turn, &(turn->a_actions->head), rra, a_index + 1);
	}
	else
	{
		run_and_add_action(turn, &(turn->b_actions->head), rrb, b_index + 1);
		run_and_add_action(turn, &(turn->a_actions->head), rra, a_index + 1);
	}
}

static void	place_in_best_position(t_turn *turn, int b_index)
{
	int		a_index;
	if (is_min_max(turn->stack_a,
			turn->stack_b->array[turn->stack_b->top - 1].value))
		a_index = find_min(turn->stack_a);
	else
		a_index = find_middle_spot_a(turn->stack_a,
			turn->stack_b->array[turn->stack_b->top - 1].value);
	_push_a(turn, b_index, a_index);
	add_action_list(&(turn->b_actions->head), pa);
	run_action(turn, pa, 0);
	add_lst_actions(turn);
}

void	complex_sort(t_turn *turn, int length)
{
	int		index;
	int		i;

	i = 0;
	index = 0;
	(void) length;
	while (turn->stack_b->top)
	{
		// index = search_in_range(turn, 0, length - 1);
		place_in_best_position(turn, index);
		++i;
	}
	index = find_min(turn->stack_a);
	move_to_top(turn, 'a', index);
}
