/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:57:08 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/22 18:19:10 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	push_b_elements(t_data *data, int left, int right)
{
	int	mid;
	int	i;
	int	down;
	int	dist;

	dist = right - left;
	mid = left + dist / 2 + dist % 2 ;
	i = 0;
	down = 0;
	while (i < ((dist + 1) / 2))
	{
		if (data->stack_a->array[data->stack_a->top - 1].value > right)
			down = 1;
		if (data->stack_a->array[data->stack_a->top - 1].value < mid)
		{
			run_action(data, pb, 1);
			++i;
		}
		else if (data->stack_a->array[0].value < mid || down)
			run_action(data, rra, 1);
		else if (data->stack_a->array[data->stack_a->top - 1].value >= mid)
			run_action(data, ra, 1);
	}
	return (mid);
}

void	push_b(t_data *data, int left, int right)
{
	int	mid;
	int	dist;

	if (is_sorted_dir_a(data, left, right, -1))
		return ;
	dist = right - left;
	if (dist < 3)
	{
		if (dist == 2)
			sort_a_three(data, left, right);
		else if (dist == 1)
			sort_a_two(data, right);
		return ;
	}
	mid = push_b_elements(data, left, right);
	push_b(data, mid, right);
	push_a(data, left, mid - 1);
}
