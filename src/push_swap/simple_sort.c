/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 04:00:30 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/05 22:23:33 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	sort_tree(t_turn *turn)
{
	t_stack	*stack_a;
	t_stack_element *elem0;
	t_stack_element *elem1;
	t_stack_element *elem2;


	stack_a = turn->stack_a;
	elem0 = stack_a->tail;
	elem1 = elem0->next;
	elem2 = elem1->next;
	if (elem0->value > elem1->value &&
			elem1->value < elem2->value &&
			elem2->value < elem0->value)
		run_action(turn, sa, 1);
	else if (elem0->value < elem1->value &&
			elem1->value < elem2->value)
	{	
		run_action(turn, sa, 1);
		run_action(turn, rra, 1);
	}
	else if (elem0->value > elem1->value &&
			elem1->value < elem2->value &&
			elem2->value > elem0->value)
		run_action(turn, ra, 1);
	else if (elem0->value < elem1->value &&
			elem1->value > elem2->value &&
			elem2->value < elem0->value)
	{	
		run_action(turn, sa, 1);
		run_action(turn, ra, 1);
	}
	else if (elem0->value < elem1->value &&
			elem1->value > elem2->value &&
			elem2->value > elem0->value)
		run_action(turn, rra, 1);
}

static void	sort_five(t_turn *turn)
{
	t_stack_element *founded;

	run_action(turn, pb, 1);
	run_action(turn, pb, 1);
	sort_tree(turn);
	while (turn->stack_b->top)
	{
		if (is_min_max(turn->stack_a, 
				*(turn->stack_b->top)))
		{

			founded = find_min(turn->stack_a);
			if (founded != NULL)
				move_to_top(turn, 'a', founded->index);
		}
		else
			find_middle_spot_a(turn, turn->stack_a,
				turn->stack_b->top->value);
		run_action(turn, pa, 1);
	}
	founded = find_min(turn->stack_a);
	if (founded != NULL)
		move_to_top(turn, 'a', founded->index);
}

void	simple_sort(t_turn *turn)
{
	if (turn->stack_a->length == 2)
		run_action(turn, sa, 1);
	if (turn->stack_a->length == 3)
		sort_tree(turn);
	if (turn->stack_a->length == 5)
		sort_five(turn);
}
