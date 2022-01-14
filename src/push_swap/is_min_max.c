/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:29:10 by tbareich          #+#    #+#             */
/*   Updated: 2022/01/14 17:51:42 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

char	is_min_max(t_stack *stack_b, int value)
{
	unsigned int	i;
	char			is_max;
	char			is_min;

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
