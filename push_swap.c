/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:58:31 by tbareich          #+#    #+#             */
/*   Updated: 2022/01/02 00:58:31 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		main(int ac, char **av)
{
	t_turn	turn;
	t_stack	stack_a;
	t_stack	stack_b;
	t_visualization visualizator;

	if (init_stack(&stack_a, ac - 1))
		error(MEMOERROR);
	if (init_stack(&stack_b, ac - 1))
		error(MEMOERROR);
	if (ac < 2)
		return (0);
	turn.stack_b = &stack_b;
	turn.stack_a = &stack_a;
	turn.b_actions = NULL;
	turn.a_actions = NULL;
	turn.visualizator = &visualizator;
	check_args(&turn ,ac, av);
	visualizator.options |= 2;
	visualizator.options |= 1;
	init_visualizator(&visualizator);
	if (is_sorted(turn))
		return (0);
	if (ac == 3)
		run_action(&turn, sa, 1);
	else
	{
		sort_by_chanks(&turn, ac - 1);
		while (stack_b.top)
			run_action(&turn, pa, 1);
	}
	loop_program(&visualizator);
	return (0);
}