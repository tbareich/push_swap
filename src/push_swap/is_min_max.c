/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:29:10 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/05 01:17:29 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

char	is_min_max(t_stack *stack, t_stack_element element)
{
	char			is_max;
	char			is_min;
	t_stack_element *current;

	is_max = 1;
	is_min = 1;
	current = stack->tail;
	while (current)
	{
		if (current->value > element.value)
			is_max = 0;
		if (current->value < element.value)
			is_min = 0;
		current = current->next;
	}
	return (is_max || is_min);
}
