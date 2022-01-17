/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_element_position.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:04:40 by tbareich          #+#    #+#             */
/*   Updated: 2022/01/16 06:25:40 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	find_middle_spot_a(t_turn *turn, t_stack *stack, int number)
{
	int		i;
	int		index;

	if (stack->top < 2)
		return ;
	i = 0;
	index = -1;
	while (i < (int)(stack->top - 1))
	{
		if (number < stack->array[i] && number > stack->array[i + 1])
		{
			index = i;
			break ;
		}
		++i;
	}
	if (index != -1)
		move_to_top(turn, 'a', index);
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
		if (number > stack->array[i] && number < stack->array[i + 1])
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
	int				max;
	int				max_index;
	unsigned int	i;

	if (stack->top < 1)
		return (-1);
	max = stack->array[0];
	max_index = 0;
	i = 0;
	while (i < stack->top)
	{
		if (stack->array[i] > max)
		{
			max = stack->array[i];
			max_index = i;
		}
		++i;
	}
	return (max_index);
}

int	find_min(t_stack *stack)
{
	int				min;
	int				min_index;
	unsigned int	i;

	if (stack->top < 1)
		return (-1);
	min = stack->array[0];
	min_index = 0;
	i = 0;
	while (i < stack->top)
	{
		if (stack->array[i] < min)
		{
			min = stack->array[i];
			min_index = i;
		}
		++i;
	}
	return (min_index);
}