/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_in_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 02:25:54 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/12 09:52:17 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	find_middle_spot_index(t_turn *turn, int number)
{
	int		i;
	t_stack	*stack_a;

	stack_a = turn->stack_a;
	if (stack_a->top < 2)
		return (-1);
	i = 0;
	while (i < (int)(stack_a->top - 1))
	{
		if (number < stack_a->array[i].value && number
				> stack_a->array[i + 1].value)
			return (i);
		++i;
	}
	return (-1);
}

int	find_min_index(t_stack *stack_a)
{
	int			min;
	int			min_index;
	int			i;

	if (stack_a->top < 2)
		return (-1);
	min = MAX_INT;
	min_index = -1;
	i = 0;
	while (i < stack_a->top)
	{
		if (stack_a->array[i].value <= min)
		{
			min = stack_a->array[i].value;
			min_index = i;
		}
		++i;
	}
	return (min_index);
}

static t_range	find_best_range(t_stack *stack, int min, int max)
{
	int		upper_bound;
	int		lower_bound;
	int		top_length;
	int		bottom_length;
	int		max_lower_bound;
	int		min_upper_bound;

	upper_bound = stack->top - 1;
	lower_bound = 0;
	top_length = 0;
	bottom_length = 0;
	while (lower_bound <= upper_bound)
	{

		if (ft_between(stack->array[upper_bound].value, min, max))
		{
			top_length += (min_upper_bound - upper_bound) * (lower_bound + 1);
			min_upper_bound = upper_bound;
		}
		if (ft_between(stack->array[lower_bound].value, min, max)
				&& lower_bound != upper_bound)
		{
			bottom_length += (lower_bound - max_lower_bound) * (lower_bound + 1);
			max_lower_bound = lower_bound;
		}
		++lower_bound;
		--upper_bound;
	}
	if (top_length == 0 && bottom_length == 0)
		return (none);
	if (top_length <= bottom_length && top_length != 0)
		return (upper_half);
	return (lower_half);
}

int	search_in_range(t_stack *stack, int min, int max)
{
	int		top;
	int		bottom;

	bottom = 0;
	top = stack->top - 1;
	while (bottom <= top )
	{

		if (ft_between(stack->array[top].value, min, max))
			return (top);
		if (ft_between(stack->array[bottom].value, min, max))
			return (bottom);
		++bottom;
		--top;
	}
	return (-1);
}

int	push_best_range(t_turn *turn, t_stack *stack, char name, int min, int max)
{
	int		upper_bound;
	int		lower_bound;
	int		i;
	int		index;
	t_range	best_range;

	best_range = find_best_range(stack, min, max);
	if (best_range == none || stack->top < 1)
		return (-1);
	upper_bound = stack->top - 1;
	lower_bound = 0;
	i = stack->top / 2 + 1;
	while (i)
	{
		index = -1;
		if (best_range == upper_half && ft_between(stack->array[upper_bound].value, min, max))
			index = upper_bound;
		else if (best_range == lower_half
			&& ft_between(stack->array[lower_bound].value, min, max))
			index = lower_bound;
		--upper_bound;
		++lower_bound;
		if (index != -1)
		{
			move_to_top(turn, name, index);
			if (name == 'a')
				run_action(turn, pb, 1);
			else
				run_action(turn, pa, 1);
			lower_bound = 0;
			upper_bound =  stack->top - 1;
		}
		--i;
	}
	return (0);
}