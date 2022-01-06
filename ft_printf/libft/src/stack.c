/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:57:00 by tbareich          #+#    #+#             */
/*   Updated: 2022/01/06 11:28:18 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		init_stack(t_stack *stack, unsigned length)
{
	if (stack == NULL)
		return (1);
	stack->array = malloc(length * sizeof(int));
	if (stack->array == NULL)
		return (1);
	stack->top = 0;
	stack->length = length;
	return 0;
}

char		push_stack(t_stack *stack, int number)
{
	if (stack == NULL || stack->length == stack->top)
		return (1);
	stack->array[stack->top] =  number;
	stack->top += 1;
	return (0);
}

int			*pop_stack(t_stack *stack)
{
	if (stack == NULL || stack->top == 0)
		return (NULL);
	stack->top -= 1;
	return (stack->array + stack->top);
}

void		print_stack(t_stack *stack)
{
	unsigned	i;

	if (stack == NULL)
	{
		ft_putendl("empty");
		return ;
	}
	i = 0;
	ft_putstr("{\n\ttop: ");
	ft_putnbr(stack->top);
	ft_putstr(",\n\tarray: [ ");
	while (i < stack->top)
	{
		ft_putnbr(stack->array[i]);
		if (i < stack->top - 1)
			ft_putstr(" ,");
		++i;
	}
	ft_putendl(" ]");
	ft_putendl("}");
}