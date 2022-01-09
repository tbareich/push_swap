/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 03:36:53 by tbareich          #+#    #+#             */
/*   Updated: 2022/01/09 23:20:58 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	move_to_top(t_stack *stack, char stack_name, int index)
{
	int		i;

	if (index >= (int)((stack->top / 2) - 1))
	{
		i = stack->top - 1 - index;
		while (i)
		{
			rx(stack);
			ft_putchar('r');
			ft_putchar(stack_name);
			ft_putstr("\n");
			--i;
		}
	}
	else {
		i = index + 1;
		while (i)
		{
			rrx(stack);
			ft_putstr("rr");
			ft_putchar(stack_name);
			ft_putstr("\n");
			--i;
		}
	}
}