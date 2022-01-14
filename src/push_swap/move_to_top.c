/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 03:36:53 by tbareich          #+#    #+#             */
/*   Updated: 2022/01/14 12:39:58 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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
		while (i)
		{
			run_action(turn, ra, 0);
			add_action(&(turn->a_actions), ra);
			--i;
		}
	}
	else {
		i = index + 1;
		turn->a_rotate_type = rra;
		turn->a_rotate_length = i;
		while (i)
		{
			run_action(turn, rra, 0);
			add_action(&(turn->a_actions), rra);
			--i;
		}
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
		while (i)
		{
			run_action(turn, rb, 0);
			add_action(&(turn->b_actions), rb);
			--i;
		}
	}
	else {
		i = index + 1;
		while (i)
		{
			run_action(turn, rrb, 0);
			add_action(&(turn->b_actions), rrb);
			--i;
		}
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
		while (i)
		{
			if (stack_name == 'a')
			{
				run_action(turn, ra, 0);
				add_action(&(turn->a_actions), ra);
			}
			else
			{
				run_action(turn, rb, 0);
				add_action(&(turn->b_actions), rb);
			}
			--i;
		}
	}
	else {
		i = index + 1;
		while (i)
		{
			if (stack_name == 'a')
			{
				run_action(turn, rra, 0);
				add_action(&(turn->a_actions), rra);
			}
			else
			{
				run_action(turn, rrb, 0);
				add_action(&(turn->b_actions), rrb);
			}
			--i;
		}
	}
}