/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 09:34:56 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/05 22:17:45 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sx(t_stack *stack)
{
	t_stack_element *new_top;
	int				index;

	if (stack->length > 1)
	{
		new_top = stack->top->prev;
		stack->top->prev = new_top->prev;			
		stack->top->prev->next = stack->top;			
		stack->top->next = new_top;
		new_top->prev = stack->top;
		new_top->next = NULL;
		index = stack->top->index;
		stack->top->index = new_top->index;
		new_top->index = index; 
		stack->top = new_top;
	}
}