/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_element_position.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:04:40 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/03 17:27:16 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	find_middle_spot_a(t_stack *stack, int number)
{
	int		i;
	int		index;

	if (stack->top < 2)
		return (-1);
	i = 0;
	index = -1;
	while (i < (int)(stack->top - 1))
	{
		if (number < stack->array[i].value && number
				> stack->array[i + 1].value)
		{
			index = i;
			break ;
		}
		++i;
	}
	return (index);
}

void	find_middle_spot_b(t_turn *turn, t_stack *stack, int number)
{
	int		i;
	int		index;

	if (stack->top < 2)
		return ;
	i = 0;
	index = -1;
	while (i < (int)(stack->top - 1))
	{
		if (number > stack->array[i].value && number
				< stack->array[i + 1].value)
		{
			index = i;
			break ;
		}
		++i;
	}
	if (index != -1)
		move_to_top_b_optimized(turn, index);
}

int	find_max(t_stack *stack)
{
	int	max;
	int	max_index;
	int	i;

	if (stack->top < 1)
		return (-1);
	max = stack->array[0].value;
	max_index = 0;
	i = 0;
	while (i < stack->top)
	{
		if (stack->array[i].value > max)
		{
			max = stack->array[i].value;
			max_index = i;
		}
		++i;
	}
	return (max_index);
}

int	find_min(t_stack *stack)
{
	int	min;
	int	min_index;
	int	i;

	if (stack->top < 1)
		return (-1);
	min = stack->array[0].value;
	min_index = 0;
	i = 0;
	while (i < stack->top)
	{
		if (stack->array[i].value < min)
		{
			min = stack->array[i].value;
			min_index = i;
		}
		++i;
	}
	return (min_index);
}
