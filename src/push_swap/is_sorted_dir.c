/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 00:58:29 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/08 00:59:05 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>


char	is_sorted_dir(t_turn *turn, t_stack *stack, char name
						, int left, int right, int dir)
{
	int	i;
	int	max_idx;
	int	length;

	if (stack->top < 2)
		return (1);
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
			if ((stack->array[i].value - stack->array[stack->top - 1].value)
					* dir > 0)
				return (0);
			i = stack->top - 1;
		}
		else
		{
			if ((stack->array[i].value - stack->array[i - 1].value) * dir > 0)
				return (0);
			--i;
		}
		--length;
	}
	if (max_idx != stack->top)
		move_to_top(turn, name, max_idx);
	return (1);
}
