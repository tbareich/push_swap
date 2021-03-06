/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:29:10 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/28 13:52:46 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

char	is_min_max(t_stack *stack, int value)
{
	int		i;
	char	is_max;
	char	is_min;

	is_max = 1;
	is_min = 1;
	i = 0;
	while (i < stack->top)
	{
		if (stack->array[i].value > value)
			is_max = 0;
		if (stack->array[i].value < value)
			is_min = 0;
		++i;
	}
	return (is_max || is_min);
}
