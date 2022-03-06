/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 03:36:53 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/06 17:34:34 by tbareich         ###   ########.fr       */
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

static void	run_and_print(t_turn *turn,
			t_operation operation, int index)
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
	int			ra_length;
	int			rra_length;

	stack = turn->stack_a;
	ra_length = stack->top - 1 - index;
	rra_length = index + 1;
	if (turn->b_rotate_type == rb)
		if (ra_length < turn->b_rotate_length)
			ra_length = turn->b_rotate_length - ra_length;
	if (turn->b_rotate_type == rrb)
		if (rra_length < turn->b_rotate_length)
			rra_length = turn->b_rotate_length - rra_length;
	if (ra_length <= rra_length)
	{
		i = stack->top - 1 - index;
		run_and_add_action(turn, &(turn->a_actions->head), ra, i);
	}
	else
	{
		i = index + 1;
		run_and_add_action(turn, &(turn->a_actions->head), rra, i);
	}
}

void	move_to_top_b_optimized(t_turn *turn, int index)
{
	int			i;
	t_stack		*stack;


	stack = turn->stack_b;
	if (index >= ((stack->top / 2) - 1))
	{
		i = stack->top - 1 - index;
		turn->b_rotate_type = rb;
		turn->b_rotate_length = i;
		run_and_add_action(turn, &(turn->b_actions->head), rb, i);
	}
	else
	{
		i = index + 1;
		turn->b_rotate_type = rrb;
		turn->b_rotate_length = i;
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
		{
			run_and_print(turn, ra, i);
			turn->a_rotate_length += 1;
		}
		else
		{
			run_and_print(turn, rb, i);
			turn->b_rotate_length += 1;
		}
	}
	else
	{
		i = index + 1;
		if (stack_name == 'a')
		{
			run_and_print(turn, rra, i);
			turn->a_rotate_length -= 1;
		}
		else
		{
			run_and_print(turn, rrb, i);
			turn->b_rotate_length -= 1;
		}
	}
}