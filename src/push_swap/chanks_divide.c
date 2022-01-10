/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chanks_divide.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 01:54:03 by tbareich          #+#    #+#             */
/*   Updated: 2022/01/07 08:15:10 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	chanks_divide(t_turn *turn, int length)
{
	int		chank;
	int		divider;
	int		number_index;
	int 	step;

	if (length <= 1)
		return ;
	else if (length <= 10)
		divider = 1;
	else if (length <= 100)
		divider = 5;
	else
		divider = 11;
	chank = length / divider;
	step = chank;
	while (turn->stack_a->top)
	{
		number_index = search_in_range(turn, chank);
		if (number_index == -1)
		{
			chank += step;
			continue ;
		}
		move_to_top(turn->stack_a, 'a', number_index);
		if (is_min_max(turn->stack_b, 
			turn->stack_a->array[turn->stack_a->top - 1]))
		{
			number_index = find_min(turn->stack_b);
			if (number_index != - 1)
				move_to_top(turn->stack_b, 'b', number_index);		
		}
		else
			find_best_spot(turn, turn->stack_a->array[turn->stack_a->top - 1]);
		px(turn->stack_b, turn->stack_a);
		ft_putendl("pb");
	}
	number_index = find_min(turn->stack_b);
	// print_stack(turn->stack_b);
	if (number_index != -1)
		move_to_top(turn->stack_b, 'b', number_index);	
	// print_stack(turn->stack_b);
}