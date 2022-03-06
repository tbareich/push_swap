/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:38:33 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/06 19:59:06 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>


static void	ajust_b_positions(t_turn *turn)
{
	int	i;
	int	sign;

	i = ft_abs(turn->b_rotate_length);
	sign = -1;
	if (i > 0)
		sign = 1;
	printf(">> %d\n", turn->b_rotate_length);
	while (i > 0)
	{
		if (sign <= 0)
			run_action(turn, rb, 1);
		else
			run_action(turn, rrb, 1);
		i--;
	}
	turn->b_rotate_length = 0;
}


static void	sort_two(t_turn *turn, int left, int right)
{
	int		top;
	t_stack *stack;
	int i = 0;
	
	while (i < 2)
	{
		if (ft_between(turn->stack_b->array[0].value, left, right))
			move_to_top(turn, 'b', 0);
		i++;
	}
	stack = turn->stack_b;
	top = stack->top;
	if (stack->array[top - 1].value < stack->array[top - 2].value)
		run_action(turn, sb, 1);
}

static void	sort_three(t_turn *turn, int left, int right)
{
	int		top;
	t_stack *stack;
	int i = 0;
	
	while (i < 3)
	{
		if (ft_between(turn->stack_b->array[0].value, left, right))
			move_to_top(turn, 'b', 0);
		i++;
	}
	stack = turn->stack_b;
	top = stack->top;
	if (stack->array[top - 1].value < stack->array[top - 2].value 
		&& stack->array[top - 1].value < stack->array[top - 3].value)
		run_action(turn, sb, 1);
	if (stack->array[top - 2].value < stack->array[top - 1].value
			&& stack->array[top - 2].value < stack->array[top - 3].value)
	{
		run_action(turn, rb, 1);
		run_action(turn, sb, 1);
		run_action(turn, rrb, 1);
	}
	if (stack->array[top - 1].value < stack->array[top - 2].value )
		run_action(turn, sb, 1);
}

void	push_a(t_turn *turn, int left, int right)
{
	int	mid;
	int	dist;
	int	index;

	dist = right - left;
	mid = left + dist / 2 + dist % 2;
	if (dist < 3)
	{
		// ajust_b_positions(turn);
		if (dist == 2)
		{
			sort_three(turn, left, right);
			run_action(turn, pa, 1);
		}
		else
			sort_two(turn, left, right);
		run_action(turn, pa, 1);
		run_action(turn, pa, 1);
		// push_b(turn, mid + 1, right);
		return ;
	}
	index = 0;
	while (1)
	{
		index = search_in_range(turn->stack_b, mid, right);
		if (index == -1)
			break ;
		move_to_top(turn, 'b', index);
		run_action(turn, pa, 1);
	}
	// ajust_b_positions(turn);
	push_b(turn,  mid, right);
	push_a(turn, left, mid - 1);
}