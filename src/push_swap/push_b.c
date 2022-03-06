/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:57:08 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/06 19:58:45 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	ajust_a_positions(t_turn *turn)
{
	int	i;
	int	sign;

	i = ft_abs(turn->a_rotate_length);
	sign = -1;
	printf(">> %d\n", turn->a_rotate_length);
	if (i > 0)
		sign = 1;
	while (i > 0)
	{
		if (sign <= 0)
			run_action(turn, ra, 1);
		else
			run_action(turn, rra, 1);
		i--;
	}
	turn->a_rotate_length = 0;
}

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

// static void	sort_three(t_turn *turn)
// {
// 	int		top;
// 	t_stack *stack;

// 	stack = turn->stack_a;
// 	top = stack->top;
// 	if (stack->array[top - 1].value > stack->array[top - 2].value 
// 		&& stack->array[top - 1].value > stack->array[top - 3].value)
// 		run_action(turn, sa, 1);
// 	if (stack->array[top - 2].value > stack->array[top - 1].value
// 			&& stack->array[top - 2].value > stack->array[top - 3].value)
// 	{
// 		run_action(turn, ra, 1);
// 		run_action(turn, sa, 1);
// 		run_action(turn, rra, 1);
// 	}
// 	if (stack->array[top - 1].value > stack->array[top - 2].value )
// 		run_action(turn, sa, 1);
// }

static void	sort_three(t_turn *turn, int left, int right)
{
	int		top;
	t_stack *stack;
	int i = 0;

	while (i < 3)
	{
		if (ft_between(turn->stack_a->array[0].value, left, right))
			move_to_top(turn, 'a', 0);
		i++;
	}
	
	stack = turn->stack_a;
	top = stack->top;
	if (stack->array[top - 1].value > stack->array[top - 2].value 
		&& stack->array[top - 1].value > stack->array[top - 3].value)
		run_action(turn, sa, 1);
	if (stack->array[top - 2].value > stack->array[top - 1].value
			&& stack->array[top - 2].value > stack->array[top - 3].value)
	{
		run_action(turn, ra, 1);
		run_action(turn, sa, 1);
		run_action(turn, rra, 1);
	}
	if (stack->array[top - 1].value > stack->array[top - 2].value )
		run_action(turn, sa, 1);
}

void	push_b(t_turn *turn, int left, int right)
{
	int	mid;
	int	dist;
	int	index;

	dist = right - left;
	// mid = left + (dist + (dist - 1)) / 2 ;
	if (dist < 3)
	{
		if (dist == 2)
			sort_three(turn, left, right);
		else
			sort_two(turn, left, right);
		return ;
	}
	mid = left + dist / 2 + dist % 2 ;
	// ajust_b_positions(turn);
	while (1)
	{
		index = search_in_range(turn->stack_a, left, mid - 1);
		if (index == -1)
			break ;
		move_to_top(turn, 'a', index);
		run_action(turn, pb, 1);
	}
	// ajust_a_positions(turn);
	// getchar();
	push_b(turn, mid, right);
	// getchar();
	push_a(turn, left, mid - 1);
	// getchar();
}