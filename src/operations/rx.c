/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 09:48:17 by tbareich          #+#    #+#             */
/*   Updated: 2022/01/06 11:33:55 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void		rx(t_stack *stack)
{
	int	i;
	int	tmp;

	if (stack->top - 1 < 2)
		return ;
	i = stack->top - 1;
	tmp = stack->array[i];
	while (i >= 0)
	{
		if (i == 0)
		{
			stack->array[0] = tmp;
			break ;
		}
		stack->array[i] = stack->array[i - 1];
		--i;
	}
}