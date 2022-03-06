/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_in_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 02:25:54 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/06 20:05:51 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	find_middle_spot_index(t_turn *turn, int number)
{
	int		i;
	t_stack	*stack_a;

	stack_a = turn->stack_a;
	if (stack_a->top < 2)
		return (-1);
	i = 0;
	while (i < (int)(stack_a->top - 1))
	{
		if (number < stack_a->array[i].value && number
				> stack_a->array[i + 1].value)
			return (i);
		++i;
	}
	return (-1);
}

int	find_min_index(t_stack *stack_a)
{
	int			min;
	int			min_index;
	int			i;

	if (stack_a->top < 2)
		return (-1);
	min = MAX_INT;
	min_index = -1;
	i = 0;
	while (i < stack_a->top)
	{
		if (stack_a->array[i].value <= min)
		{
			min = stack_a->array[i].value;
			min_index = i;
		}
		++i;
	}
	return (min_index);
}

int	turns_length(t_turn *turn, int a_index)
{
	int		b_index;
	int	l_ra_rb;
	int	l_ra_rrb;
	int l_rra_rb;
	int l_rra_rrb;

	if (is_min_max(turn->stack_a, turn->stack_b->array[a_index].value))
		b_index = find_min_index(turn->stack_a);
	else
		b_index = find_middle_spot_index(turn, turn->stack_b->array[a_index].value);
	l_ra_rb = max(turn->stack_a->top - 1 - a_index, 
					turn->stack_b->top - 1 - b_index);
	l_ra_rrb = turn->stack_a->top - 1 - a_index + b_index + 1;
	l_rra_rb = a_index + 1 + turn->stack_b->top - 1 - b_index;
	l_rra_rrb = max(b_index + 1, a_index + 1);
	if (l_ra_rb <= l_ra_rrb &&
		l_ra_rb <= l_rra_rb &&
		l_ra_rb <= l_rra_rrb)
		return (l_ra_rb);
	if (l_ra_rrb <= l_rra_rb &&
		l_ra_rrb <= l_rra_rrb)
		return (l_ra_rrb);
	if (l_rra_rb <= l_rra_rrb)
		return (l_rra_rb);
	return (l_rra_rrb);
}

int	search_in_range(t_stack *stack, int min, int max)
{
	int		top;
	int		bottom;

	bottom = 0;
	top = stack->top - 1;
	while (bottom <= top )
	{

		if (ft_between(stack->array[top].value, min, max))
			return (top);
		if (ft_between(stack->array[bottom].value, min, max))
			return (bottom);
		++bottom;
		--top;
	}
	return (-1);
}
