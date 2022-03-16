/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:52:40 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/16 21:21:02 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_operation	rotate_a(t_turn *turn, int left, int right, t_operation opt)
{
	int down;
	int	dist;
	int mid;

	dist = right - left;
	mid = left + dist / 2 + dist % 2;
	down = turn->stack_b->array[turn->stack_b->top - 1].value < left
				|| down;
	if ((turn->stack_b->array[0].value >= mid || down) && opt == rra)
		return (rrr);
	else if (turn->stack_b->array[turn->stack_b->top - 1].value < mid
				&& opt == ra)
			return (rr);
	else
		return (opt);
}