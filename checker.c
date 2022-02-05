/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:58:27 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/05 21:52:07 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int			main(int ac, char **av)
{
	t_turn	turn;
	t_stack	stack_a;
	t_stack	stack_b;

	if (init_stack(&stack_a))
		error(MEMOERROR);
	if (init_stack(&stack_b))
		error(MEMOERROR);
	turn.stack_a = &stack_a;
	turn.stack_b = &stack_b;
	if (ac < 2)
		return (0);
	reader(&turn, ac, av);
	if (is_sorted(turn))
		ft_putendl("OK");
	else
		ft_putendl("KO");
}