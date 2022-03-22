/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_turn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 00:11:56 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/22 02:20:39 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	free_turn(t_turn *turn)
{
	if (turn->stack_a->array != NULL)
		stack_del_content(turn->stack_b);
	stack_del_content(turn->stack_a);
	return (0);
}
