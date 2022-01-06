/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:06:17 by tbareich          #+#    #+#             */
/*   Updated: 2022/01/06 11:34:04 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <push_swap.h>

void		rrx(t_stack *stack)
{
	unsigned	i;
	int			tmp;

	if (stack->top - 1 < 2)
		return ;
	i = 0;
	tmp = stack->array[i];
	while (i < stack->top)
	{
		if (i == stack->top - 1)
		{
			stack->array[i] = tmp;
			break ;
		}
		stack->array[i] = stack->array[i + 1];
		++i;
	}
}