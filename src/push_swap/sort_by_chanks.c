/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_chanks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 01:54:03 by tbareich          #+#    #+#             */
/*   Updated: 2022/01/07 08:15:10 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	find_middle_spot(t_turn *turn, int number)
{
	int		i;
	int		index;
	t_stack	*stack_b;


	stack_b = turn->stack_b;
	if (stack_b->top < 2)
		return ;
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
		move_to_top_b_optimized(turn, index);
}

static int	find_max(t_stack *stack_b)
{
	int			max;
	int			max_index;
	unsigned	i;

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

void		sort_by_chanks(t_turn *turn, int length)
{
	int		chank;
	int		divider;
	int		number_index;
	int 	step;

	if (length <= 1)
		return ;
	else if (length <= 5)
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
		move_to_top_a_optimized(turn, number_index);
		if (is_min_max(turn->stack_b, 
			turn->stack_a->array[turn->stack_a->top - 1]))
		{
			number_index = find_max(turn->stack_b);
			if (number_index != - 1)
				move_to_top_b_optimized(turn, number_index);		
		}
		else
			find_middle_spot(turn, turn->stack_a->array[turn->stack_a->top - 1]);
		add_action(&(turn->a_actions), pb);
		run_action(turn, pb, 0);
		print_lst_actions(turn);
	}
	number_index = find_max(turn->stack_b);
	if (number_index != -1)
		move_to_top(turn, 'b', number_index);	
	print_lst_actions(turn);
}