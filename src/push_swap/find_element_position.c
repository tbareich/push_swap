/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_element_position.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:04:40 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/05 21:39:56 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	find_middle_spot_a(t_turn *turn, t_stack *stack, int number)
{
	int		index;
	t_stack_element	*current;

	if (stack->length < 2)
		return ;
	index = -1;
	current = stack->tail;
	while (current->next)
	{
		if (number < current->value && number > current->next->value)
		{
			index = get_index(*stack, *current);
			break ;
		}
		current = current->next;
	}
	if (index != -1)
		move_to_top(turn, 'a', index);
}

void	find_middle_spot_b(t_turn *turn, t_stack *stack, int number)
{
	int		index;
	t_stack_element	*current;

	if (stack->length < 2)
		return ;
	index = -1;
	current = stack->tail;
	while (current->next)
	{
		if (number > current->value && number < current->next->value)
		{
			index = get_index(*stack, *current);
			break ;
		}
		current = current->next;
	}
	if (index != -1)
		move_to_top_b_optimized(turn, index);
}

t_stack_element	*find_max(t_stack *stack)
{
	t_stack_element	*max;
	t_stack_element	*current;

	if (stack->length < 1)
		return (NULL);
	current = stack->tail;
	max = current;
	while (current)
	{
		if (current->value > max->value)
			max = current;
		current = current->next;
	}
	return (max);
}

t_stack_element	*find_min(t_stack *stack)
{
	t_stack_element	*min;
	t_stack_element	*current;

	if (stack->length < 1)
		return (NULL);
	current = stack->tail;
	min = current;
	while (current)
	{
		if (current->value < min->value)
			min = current;
		current = current->next;
	}
	return (min);
}
