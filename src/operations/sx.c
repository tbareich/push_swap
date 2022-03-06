/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 09:34:56 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/15 21:42:11 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sx(t_stack *stack)
{
	if (stack->top > 1)
		ft_swap(stack->array + stack->top - 1, stack->array + stack->top - 2);
}
