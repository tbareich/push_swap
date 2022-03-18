/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 03:36:53 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/17 18:46:51 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	run_and_print(t_turn *turn,
			t_operation operation, int index)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = turn->stack_a;
	stack_b = turn->stack_b;
	while (index)
	{
		if (operation == ra || operation == rra || operation == sa )
			run_action(turn, need_merge(turn, operation), 1);
		else 
			run_action(turn, operation, 1);
		--index;
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
	if (index > stack->top - 1 || index < 0)
		return ;
	if (index >= ((stack->top / 2)))
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

void	move_to_top_b(t_turn *turn, int left, int right, int index)
{
	int		i;
	t_stack	*stack;

	stack = turn->stack_b;
	if (index > stack->top - 1 || index < 0)
		return ;
	if (index >= ((stack->top / 2) - 1))
	{
		i = stack->top - 1 - index;
		run_and_print(turn, rb, i);
		turn->b_rotate_length += 1;
	}
	else
	{
		i = index + 1;
		run_and_print(turn, rrb, i);
		turn->b_rotate_length -= 1;
	}
}

void	move_to_top_a(t_turn *turn, int left, int right, int index)
{
	int		i;
	t_stack	*stack;

	stack = turn->stack_a;
	if (index > stack->top - 1 || index < 0)
		return ;
	if (index >= ((stack->top / 2) - 1))
	{
		i = stack->top - 1 - index;
		run_and_print(turn, rotate_a(turn, left, right, ra), i);
		turn->b_rotate_length += 1;
	}
	else
	{
		i = index + 1;
		run_and_print(turn, rotate_a(turn, left, right, rra), i);
		turn->b_rotate_length -= 1;
	}
}