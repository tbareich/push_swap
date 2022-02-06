/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_in_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 02:25:54 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/06 09:51:11 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	find_middle_spot_index(t_turn *turn, int number)
{
	int		i;
	int		index;
	t_stack	*stack_b;


	stack_b = turn->stack_b;
	if (stack_b->top < 2)
		return (-1);
	i = 0;
	index = -1;
	while (i < (int)(stack_b->top - 1))
	{
		if (number > stack_b->array[i] && number < stack_b->array[i + 1])
		{
			index = i;
			break ;
		}
		++i;
	}
	return (index);
}


int	find_max_index(t_stack *stack_b)
{
	int			max;
	int			max_index;
	int			i;

	if (stack_b->top < 2)
		return -1;
	max = MIN_INT;
	max_index = -1;
	i = 0;
	while (i < stack_b->top)
	{
		if (stack_b->array[i] >= max)
		{
			max = stack_b->array[i];
			max_index = i;
		}
		++i;
	}
	return (max_index);
}


int	turns_length(t_turn *turn, int index)
{
	int		elem_index;
	t_stack	*stack_b;
	t_stack	*stack_a;
	int		a_i_length;
	int		b_i_length;


	stack_b = turn->stack_b;
	stack_a = turn->stack_a;
	a_i_length = min(index + 1, stack_a->top - index - 1);
	b_i_length = 0;
	if (is_min_max(stack_b, stack_a->array[index]))
	{
		elem_index = find_max_index(turn->stack_b);
		b_i_length = min(elem_index + 1, stack_b->top - elem_index - 1);
	}
	else
	{
		elem_index = find_middle_spot_index(turn, stack_a->array[index]);
		if (elem_index != -1)
			b_i_length = min(elem_index + 1, stack_b->top - elem_index - 1);
	}
	return (max(a_i_length, b_i_length));
}



int	search_in_range(t_turn *turn, int min, int max)
{
	int		index;
	int		best;
	int		best_index;
	int		turns;

	index = 0;
	best_index = -1;
	best = MAX_INT;
	while (index < (int)turn->stack_a->top)
	{
		if (turn->stack_a->array[index] <= max
				&& turn->stack_a->array[index] >= min)
		{
			turns = turns_length(turn, index);
			if (turns < best)
			{
				best = turns;
				best_index = index;
			}
		}
		++index;
	}
	// ft_printf("%d\n", best);
	return (best_index);
}