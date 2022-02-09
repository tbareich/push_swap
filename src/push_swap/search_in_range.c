/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_in_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 02:25:54 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/09 09:55:02 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack_element	*find_middle_spot(t_turn *turn, t_stack_element element)
{
	t_stack			*stack_b;
	t_stack_element	*node;
	t_stack_element	*current;

	stack_b = turn->stack_b;
	if (stack_b->length < 2)
		return (NULL);
	current = stack_b->tail;
	node = NULL;
	while (current->next)
	{
		if (element.value > current->value
				&& element.value < current->next->value)
		{
			node = current;
			break ;
		}
		current = current->next;
	}
	return (node);
}

int	turns_length(t_turn *turn, t_stack_element element)
{
	t_stack_element	*founded_elem;
	t_stack			*stack_b;
	t_stack			*stack_a;
	int				a_i_length;
	int				b_i_length;

	stack_b = turn->stack_b;
	stack_a = turn->stack_a;
	a_i_length = min(get_index(*stack_a, element) + 1, stack_a->length
					- get_index(*stack_a, element) - 1);
	b_i_length = 0;
	if (is_min_max(stack_b, element))
	{
		founded_elem = find_max(turn->stack_b);
		if (founded_elem)
			b_i_length = min(get_index(*stack_b, *founded_elem) + 1, 
					stack_b->length - get_index(*stack_b, *founded_elem) - 1);
	// ft_printf("hello\n");
	}
	else
	{
		founded_elem = find_middle_spot(turn, element);
		if (founded_elem && get_index(*stack_b, *founded_elem) != -1)
			b_i_length = min(get_index(*stack_b, *founded_elem) 
				+ 1, stack_b->length - get_index(*stack_b, *founded_elem) - 1);
	}
	return (max(a_i_length, b_i_length));
}



t_stack_element	*search_in_range(t_turn *turn, int min, int max)
{
	int				index;
	int				best;
	int				turns;
	t_stack_element *current;
	t_stack_element *element;

	best = MAX_INT;
	element = NULL;
	current = turn->stack_a->tail;
	index = 0;
	while (current)
	{
		if (current->value <= max
				&& current->value >= min)
		{
			turns = turns_length(turn, *current);
			if (turns < best)
			{
				best = turns;
				element = current;
			}
		}
		++index;
		current = current->next;
	}
	return (element);
}