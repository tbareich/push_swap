/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:57:00 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/09 16:05:51 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	init_stack(t_stack *stack, int length)
{
	if (stack == NULL)
		return (1);
	stack->array = (int *)malloc(length * sizeof(int));
	if (stack->array == NULL)
		return (1);
	stack->top = 0;
	stack->length = length;
	return (0);
}

char	push_stack(t_stack *stack, int number)
{
	if (stack == NULL || stack->length == stack->top)
		return (1);
	stack->array[stack->top] = number;
	stack->top += 1;
	return (0);
}

int	*pop_stack(t_stack *stack)
{
	if (stack == NULL || stack->top == 0)
		return (NULL);
	stack->top -= 1;
	return (stack->array + stack->top);
}

void	stack_del(t_stack **stack)
{
	ft_memdel((void **)&((*stack)->array));
	ft_memdel((void **)stack);
}
