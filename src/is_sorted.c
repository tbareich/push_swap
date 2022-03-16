/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 21:18:55 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/08 22:07:47 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

char	is_sorted(t_stack *stack)
{
	int		i;

	if (stack->top < 2)
		return (1);
	i = stack->top - 1;
	while (i > 0)
	{
		if (stack->array[i].value > stack->array[i - 1].value)
			return (0);
		--i;
	}
	return (1);
}