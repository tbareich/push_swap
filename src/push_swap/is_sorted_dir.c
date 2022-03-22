/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 00:58:29 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/22 00:06:35 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	find_up_index(t_stack *stack, int left, int right)
{
	int	i;
	int	up_index;

	i = 0;
	up_index = stack->top - 1;
	while (i < stack->top)
	{
		if (ft_between(stack->array[i].value, left, right))
			up_index = i;
		else
			break ;
		i++;
	}
	return (up_index);
}

static int	is_sorted_dir(t_stack *stack, int left, int right,
			int dir)
{
	int	i;
	int	up_index;
	int	length;

	up_index = find_up_index(stack, left, right);
	i = up_index;
	length = right - left;
	while (length)
	{
		if (i != up_index
			&& (stack->array[ft_modulo(i, stack->top)].value
				- stack->array[ft_modulo(i - 1, stack->top)].value)
			* dir < 0)
			return (-1);
		--i;
		--length;
	}
	return (up_index);
}

char	is_sorted_dir_a(t_turn *turn, int left, int right, int dir)
{
	int	up_index;

	up_index = is_sorted_dir(turn->stack_a, left, right, dir);
	if (up_index < 0)
		return (0);
	if (turn->stack_a->array[up_index].value != left
		&& turn->stack_a->array[up_index].value != left + 1)
		return (0);
	move_to_top(turn, 'a', up_index);
	if ((turn->stack_a->array[turn->stack_a->top - 1].value
			- turn->stack_a->array[turn->stack_a->top - 2].value) * dir < 0)
		run_action(turn, sa, 1);
	return (1);
}

char	is_sorted_dir_b(t_turn *turn, int left, int right, int dir)
{
	int	up_index;

	up_index = is_sorted_dir(turn->stack_b, left, right, dir);
	if (up_index < 0)
		return (0);
	if (turn->stack_b->array[up_index].value != right
		&& turn->stack_b->array[up_index].value != right - 1)
		return (0);
	move_to_top(turn, 'b', up_index);
	if ((turn->stack_b->array[turn->stack_b->top - 1].value
			- turn->stack_b->array[turn->stack_b->top - 2].value) * dir < 0)
		run_action(turn, sb, 1);
	return (1);
}
