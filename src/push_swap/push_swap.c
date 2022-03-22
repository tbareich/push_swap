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

static void	init_turn(t_turn *turn, int *ac, char ***av)
{
	turn->visualizator.turn = 0;
	turn->visualizator.options = 0;
	turn->options_length = set_options(&(turn->visualizator), *ac, *av);
	*ac = *ac - turn->options_length;
	*av = *av + turn->options_length;
}

int	main(int ac, char **av)
{
	t_turn			turn;
	t_stack			stack_a;
	t_stack			stack_b;

	init_turn(&turn, &ac, &av);
	if (ac < 2)
		return (free_turn(&turn));
	turn.stack_a = &stack_a;
	turn.stack_b = &stack_b;
	if (init_stack(turn.stack_a, ac - 1))
		error(&turn, MEMOERROR);
	if (init_stack(turn.stack_b, ac - 1))
		error(&turn, MEMOERROR);
	check_args(&turn, ac, av);
	if (is_sorted(&stack_a))
		return (free_turn(&turn));
	if (is_option_activated(turn.visualizator.options, V_OPTION))
		init_visualiser(&(turn.visualizator));
	if (ac <= 6)
		simple_sort(&turn);
	else
		push_b(&turn, 0, stack_a.length - 1);
	if (is_option_activated(turn.visualizator.options, V_OPTION))
		loop_program(&(turn.visualizator));
	return (free_turn(&turn));
}
