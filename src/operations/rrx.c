/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:06:17 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/06 09:52:22 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <push_swap.h>

void		rrx(t_stack *stack)
{
	int	i;
	int	tmp;

	if (stack->top - 1 < 1)
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