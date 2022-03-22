/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:38:33 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/22 18:18:28 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	push_a_elements(t_data *data, int left, int right)
{
	int	mid;
	int	i;
	int	down;
	int	up_mid_length;

	mid = left + (right - left) / 2 + (right - left) % 2;
	i = 0;
	down = 0;
	up_mid_length = right - mid + 1;
	while (i < up_mid_length)
	{
		if (data->stack_b->array[data->stack_b->top - 1].value < left)
			down = 1;
		if (data->stack_b->array[data->stack_b->top - 1].value >= mid)
		{
			run_action(data, pa, 1);
			++i;
		}
		else if (data->stack_b->array[0].value >= mid || down)
			run_action(data, rrb, 1);
		else if (data->stack_b->array[data->stack_b->top - 1].value < mid)
			run_action(data, rb, 1);
	}
	return (mid);
}

void	push_a(t_data *data, int left, int right)
{
	int	dist;
	int	mid;

	dist = right - left;
	if (is_sorted_dir_b(data, left, right, 1))
	{
		while (dist-- > -1)
			run_action(data, pa, 1);
		return ;
	}
	if (dist < 3)
		return (sort_b(data, left, right, dist));
	mid = push_a_elements(data, left, right);
	push_b(data, mid, right);
	push_a(data, left, mid - 1);
}
