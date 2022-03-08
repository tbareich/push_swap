/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:57:08 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/08 00:27:48 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	sort_two(t_turn *turn, int left, int right)
{
	int		top;
	t_stack *stack;
	int i = 0;

	while (i < 2)
	{
		if (ft_between(turn->stack_a->array[0].value, left, right))
			move_to_top(turn, 'a', 0);
		i++;
	}
	stack = turn->stack_a;
	top = stack->top;
	if (stack->array[top - 1].value > stack->array[top - 2].value)
		run_action(turn, sa, 1);
}

void	push_b(t_turn *turn, int left, int right)
{
	int	mid;
	int	dist;
	int	index;
	
	if (is_sorted_dir(turn, turn->stack_a, 'a', left, right, 1))
		return ;
	dist = right - left;
	if (dist < 2)
	{
		if (dist == 1)
			sort_two(turn, left, right);;
		return ;
	}
	mid = left + dist / 2 + dist % 2 ;
	while (1)
	{
		index = search_in_range(turn->stack_a, left, mid - 1);
		if (index == -1)
			break ;
		move_to_top(turn, 'a', index);
		run_action(turn, pb, 1);
	}
	push_b(turn, mid, right);
	push_a(turn, left, mid - 1);
}