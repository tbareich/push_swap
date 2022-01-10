/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:29:10 by tbareich          #+#    #+#             */
/*   Updated: 2022/01/10 01:46:38 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

char	is_min_max(t_stack *stack_b, int value)
{
	unsigned	i;
	char		is_max;
	char		is_min;

	is_max = 1;
	is_min = 1;
	i = 0;
	while (i < stack_b->top)
	{
		if (stack_b->array[i] > value)
			is_max = 0;
		if (stack_b->array[i] < value)
			is_min = 0;
		++i;
	}
	return (is_max || is_min);
}

int		find_min(t_stack *stack_b)
{
	int			min;
	int			min_index;
	unsigned	i;

	if (stack_b->top < 2)
		return -1;
	min = MAX_INT;
	min_index = -1;
	i = 0;
	while (i < stack_b->top)
	{
		if (stack_b->array[i] <= min)
		{
			min = stack_b->array[i];
			min_index = i;
		}
		++i;
	}
	return (min_index);
}

int		find_max(t_stack *stack_b)
{
	int			max;
	int			max_index;
	unsigned	i;

	if (stack_b->top < 2)
		return -1;
	max = MIN_INT;
	max_index = -1;
	i = 0;
	while (i < stack_b->top)
	{
		if (stack_b->array[i] >= max)
		{
			max = stack_b->array[i];
			max_index = i;
		}
		++i;
	}
	return (max_index);
}