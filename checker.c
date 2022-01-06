/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:58:27 by tbareich          #+#    #+#             */
/*   Updated: 2022/01/06 04:19:52 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>


int			main(int ac, char **av)
{
	t_turn	turn;
	t_stack	stack_a;
	t_stack	stack_b;

	if (init_stack(&stack_a, ac - 1))
		error(MEMOERROR);
	if (init_stack(&stack_b, ac - 1))
		error(MEMOERROR);
	turn.stack_a = &stack_a;
	turn.stack_b = &stack_b;
	reader(&turn, ac, av);
}