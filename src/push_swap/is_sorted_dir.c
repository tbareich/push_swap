/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 00:58:29 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/17 20:33:55 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

char	is_sorted_dir(t_turn *turn, t_stack *stack, char name
						, int left, int right, int dir)
{
	int	i;
	int	max_idx;
	int	length;

	max_idx = stack->top - 1;
	i = 0;
	while (i < stack->top)
	{
		if (ft_between(stack->array[i].value, left, right))
			max_idx = i;
		else
			break ;
		i++;
	}
	i = max_idx;
	length = right - left;
	while (length)
	{
		if (i == 0)
		{
			if (i != max_idx
				&& (stack->array[i].value - stack->array[stack->top - 1].value)
				* dir < 0)
				return (0);
			i = stack->top - 1;
		}
		else
		{
			if (i != max_idx
				&& (stack->array[i].value - stack->array[i - 1].value)
				* dir < 0)
				return (0);
			--i;
		}
		--length;
	}
	if (name == 'a' && stack->array[max_idx].value != left &&
		stack->array[max_idx].value != left + 1)
		return (0);
	if (name == 'b' && stack->array[max_idx].value != right &&
		stack->array[max_idx].value != right - 1)
		return (0);
	move_to_top(turn, name, max_idx);
	if ((stack->array[stack->top - 1].value -
		stack->array[stack->top - 2].value) * dir < 0)
	{
		if (name == 'a')
			run_action(turn, sa, 1);
		if (name  == 'b')
			run_action(turn, sb, 1);
	}
	return (1);
}
