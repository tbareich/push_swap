/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ajust_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:14:40 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/16 20:51:50 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	need_ra(t_turn *turn, t_stack *stack)
{
	if (stack->top < 2)
		return ;
	if (stack->array[stack->top - 1].value
		== stack->array[stack->top - 2].value + 1)
		run_action(turn, sa, 1);
}

void	need_rb(t_turn *turn, t_stack *stack)
{
	if (stack->top < 2)
		return ;
	if (stack->array[stack->top - 1].value
		== stack->array[stack->top - 2].value - 1)
		run_action(turn, sb, 1);
}
