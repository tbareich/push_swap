/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:57:00 by tbareich          #+#    #+#             */
/*   Updated: 2022/01/03 19:54:14 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_stack		*new_stack(unsigned length, size_t size)
{
	t_stack		*stack;

	stack = (t_stack*)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->array = malloc(length * size);
	if (stack->array == NULL)
	{
		ft_memdel((void **) &stack);
		return (NULL);
	}
	stack->top = 0;
	stack->length = length;
	stack->size = size;
	return stack;
}

char		new_from_stack(t_stack *stack, unsigned length, size_t size)
{
	if (stack == NULL)
		return (1);
	stack->array = malloc(length * size);
	if (stack->array == NULL)
		return (1);
	stack->top = 0;
	stack->length = length;
	stack->size = size;
	return 0;
}

char		push_stack(t_stack *stack, void* elem)
{
	if (elem == NULL || stack == NULL || stack->length == stack->top)
		return (1);
	ft_memcpy(stack->array + (stack->top * stack->size), elem, stack->size);
	stack->top += 1;
	return (0);
}

void		*pop_stack(t_stack *stack)
{
	if (stack == NULL || stack->top == 0)
		return (NULL);
	stack->top -= 1;
	return (stack->array + stack->top + 1);
}

void		print_stack(t_stack *stack, void print(void *elem))
{
	unsigned	i;

	if (stack == NULL)
	{
		ft_putendl("empty");
		return ;
	}
	i = 0;
	ft_putstr("[ ");
	while (i < stack->length)
	{
		print(stack->array + (i * stack->size));
		if (i < stack->length - 1)
			ft_putstr(" ,");
		++i;
	}
	ft_putendl(" ]");
}