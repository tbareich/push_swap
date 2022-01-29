/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 03:36:53 by tbareich          #+#    #+#             */
/*   Updated: 2022/01/28 15:49:47 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	run_and_add_action(t_turn *turn, t_list **action,
			e_operation operation, int index)
{
	while (index)
	{
		run_action(turn, operation, 0);
		add_action(action, operation);
		--index;
	}
}

static void	run_and_print(t_turn *turn,
			e_operation operation, int index)
{
	while (index)
	{
		run_action(turn, operation, 1);
		--index;
	}
}

void	move_to_top_a_optimized(t_turn *turn, int index)
{
	int		i;
	t_stack	*stack;

	stack = turn->stack_a;
	if (index >= (int)((stack->top / 2) - 1))
	{
		i = stack->top - 1 - index;
		turn->a_rotate_type = ra;
		turn->a_rotate_length = i;
		run_and_add_action(turn, &(turn->a_actions->head), ra, i);
	}
	else
	{
		i = index + 1;
		turn->a_rotate_type = rra;
		turn->a_rotate_length = i;
		run_and_add_action(turn, &(turn->a_actions->head), rra, i);
	}
}

void	move_to_top_b_optimized(t_turn *turn, int index)
{
	int			i;
	t_stack		*stack;
	int			rb_length;
	int			rrb_length;

	stack = turn->stack_b;
	rb_length = stack->top - 1 - index;
	rrb_length = index + 1;
	if (turn->a_rotate_type == ra)
		if (rb_length < turn->a_rotate_length)
			rb_length = turn->a_rotate_length - rb_length;
	if (turn->a_rotate_type == rra)
		if (rrb_length < turn->a_rotate_length)
			rrb_length = turn->a_rotate_length - rrb_length;
	if (rb_length <= rrb_length)
	{
		i = stack->top - 1 - index;
		run_and_add_action(turn, &(turn->b_actions->head), rb, i);
	}
	else
	{
		i = index + 1;
		run_and_add_action(turn, &(turn->b_actions->head), rrb, i);
	}
}

void	move_to_top(t_turn *turn, char stack_name, int index)
{
	int		i;
	t_stack	*stack;

	if (stack_name == 'a')
		stack = turn->stack_a;
	else
		stack = turn->stack_b;
	if (index >= (int)((stack->top / 2) - 1))
	{
		i = stack->top - 1 - index;
		if (stack_name == 'a')
			run_and_print(turn, ra, i);
		else
			run_and_print(turn, rb, i);
		
	}
	else
	{
		i = index + 1;
		if (stack_name == 'a')
			run_and_print(turn, rra, i);
		else
			run_and_print(turn, rrb, i);
	}
}
