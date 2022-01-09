/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_spot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 08:34:36 by tbareich          #+#    #+#             */
/*   Updated: 2022/01/07 10:29:49 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void		find_best_spot(t_turn *turn, int number)
{
	int		i;
	int		first_index;
	int		index;
	t_stack	*stack_b;


	stack_b = turn->stack_b;
	if (stack_b->top < 2)
		return ;
	first_index = 0;
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
	if (index != -1)
		move_to_top(stack_b, 'b', index);
	// print_stack_array(stack_b);
}