/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:57:00 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/06 00:26:01 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		init_stack(t_stack *stack)
{
	if (stack == NULL)
		return (1);
	stack->top = NULL;
	stack->tail = NULL;
	stack->length = 0;
	stack->init_index = 0;
	return (0);
}

char		push_stack(t_stack *stack, int number)
{
	t_stack_element		*node;

	if (stack == NULL)
		return (1);
	node = (t_stack_element *)malloc(sizeof(t_stack_element));
	if (node == NULL)
		return (1);
	node->value = number;
	node->next = NULL;
	node->prev = NULL;
	if (stack->top == NULL)
	{
		node->index = 0;
		stack->top = node;
		stack->tail = node;
	}
	else
	{
		node->index = stack->top->index + 1;
		stack->top->next = node;
		node->prev = stack->top;
		stack->top = node;
	}
	stack->length += 1;
	return (0);
}

t_stack_element	*pop_stack(t_stack *stack)
{
	t_stack_element	*element;

	if (stack == NULL || stack->top == NULL)
		return (NULL);
	element = stack->top;
	stack->top = element->prev;
	if (stack->top == NULL)
	{
		stack->tail = NULL;
		stack->init_index = 0;
	}
	else
		stack->top->next = NULL;
	stack->length -= 1;
	return (element);
}

void		print_stack(t_stack *stack)
{
	t_stack_element	*node;

	if (stack == NULL)
	{
		ft_putendl("empty");
		return ;
	}
	ft_putstr("{\n\ttop: ");
	ft_putnbr(stack->length);
	ft_putstr(",\n\tarray: [ ");
	node = stack->tail; 
	while (node)
	{
		ft_putnbr(node->value);
		if (node->next != NULL)
			ft_putstr(", ");
		node = node->next;
	}
	ft_putendl(" ]");
	ft_putendl("}");
}

void		print_stack_array(t_stack *stack)
{
	t_stack_element	*node;

	if (stack == NULL)
	{
		ft_putendl("empty");
		return ;
	}
	ft_putstr("array: [ ");
	node = stack->tail;
	while (node)
	{
		ft_putnbr(node->value);
		if (node->next != NULL)
			ft_putstr(", ");
		node = node->next;
	}
	ft_putendl(" ]");
}

int		get_index(t_stack stack, t_stack_element element)
{
	return (stack.init_index + element.index);
}

void	stack_left_rotate(t_stack *stack)
{
	t_stack_element *new_tail;
	t_stack_element *new_top;

	if (stack == NULL || stack->top == NULL || stack->length < 2)
		return ;
	if (stack->tail->next != NULL)
	{
		new_tail = stack->tail->next;
		new_top = stack->tail;
		new_top->prev = stack->top;
		new_top->index = stack->top->index + 1;
		stack->top->next = new_top;
		stack->top = new_top;
		stack->tail = new_tail;
		new_top->next = NULL;
		new_tail->prev = NULL;
		stack->init_index -= 1;
	}
}

void	stack_right_rotate(t_stack *stack)
{
	t_stack_element *new_tail;
	t_stack_element *new_top;

	if (stack == NULL || stack->top == NULL || stack->length < 2)
		return ;
	if (stack->tail->next != NULL)
	{
		new_tail = stack->top;
		new_tail->next = stack->tail;
		new_tail->index = stack->tail->index - 1;
		stack->tail->prev = new_tail;
		stack->tail = new_tail;
		new_top = stack->top->prev;
		stack->top = new_top;
		stack->tail = new_tail;
		new_top->next = NULL;
		new_tail->prev = NULL;
		stack->init_index += 1;
	}
}