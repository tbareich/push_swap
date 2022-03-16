/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 00:58:29 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/15 16:59:58 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

char	is_sorted_dir(t_turn *turn, t_stack *stack, char name
						, int left, int right, int dir)
{
	int	i;
	int	max_idx;
	int	length;

	max_idx = stack->top - 1;
	i = 0;
	while (i < stack->top)
	{
		if (ft_between(stack->array[i].value, left, right))
			max_idx = i;
		else
			break ;
		i++;
	}
	i = max_idx;
	length = right - left;
	while (length)
	{
		if (i == 0)
		{
			if (i != max_idx
				&& (stack->array[i].value - stack->array[stack->top - 1].value)
				* dir < 0)
				return (0);
			i = stack->top - 1;
		}
		else
		{
			if (i != max_idx
				&& (stack->array[i].value - stack->array[i - 1].value)
				* dir < 0)
				return (0);
			--i;
		}
		--length;
	}
	if (name == 'a' && stack->array[max_idx].value != left &&
		stack->array[max_idx].value != left + 1)
		return (0);
	if (name == 'b' && stack->array[max_idx].value != right &&
		stack->array[max_idx].value != right - 1)
		return (0);
	move_to_top(turn, name, max_idx);
	if ((stack->array[stack->top - 1].value -
		stack->array[stack->top - 2].value) * dir < 0)
	{
		if (name == 'a')
			run_action(turn, sa, 1);
		if (name  == 'b')
			run_action(turn, sb, 1);
	}
	return (1);
}

int	is_a_sorted(t_turn *turn, int left, int right)
{
	int 	min_index;
	int		i;
	t_stack	*stack;
	int		new_right;

	stack = turn->stack_a;
	if (stack->top < 2)
		return (right);
	min_index = 0;
	i = stack->top - 1;
	while (i >= 0 && ft_between(stack->array[i].value, left, right))
	{
		min_index = i;
		--i;
	}
	new_right = right;
	i = min_index;
	if (stack->array[i % stack->top].value == right)
	{
		while (ft_between(stack->array[i % stack->top].value, left, right))
		{
			if (stack->array[i % stack->top].value
				!= stack->array[(i + 1) % stack->top].value + 1)
				break ;
			--new_right;
			if (i == min_index)
				--new_right;
			++i;
		}
	}
	return (new_right);
}

int	is_b_sorted(t_turn *turn, int left, int right)
{
	int 	max_index;
	int		i;
	t_stack	*stack;
	int		new_right;

	stack = turn->stack_b;
	if (stack->top < 2)
		return (right);
	max_index = stack->top - 1;
	i = stack->top;
	while (ft_between(stack->array[i % stack->top].value, left, right))
	{
		max_index = i;
		++i;
	}
	new_right = right;
	i = max_index;
	if (stack->array[i % stack->top].value == right)
	{
		while (ft_between(stack->array[i % stack->top].value, left, right))
		{
			if (stack->array[i % stack->top].value
				!= stack->array[(i - 1) % stack->top].value + 1)
				break ;
			--new_right;
			if (i == max_index)
				--new_right;
			--i;
		}
	}
	return (new_right);
}