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

static void	init_turn(t_turn *turn, t_visualiser *visualiser,
						int *ac, char ***av)
{
	turn->visualizator = visualiser;
	turn->visualizator->turn = 0;
	turn->visualizator->options = 0;
	turn->options_length = set_options(turn->visualizator, *ac, *av);
	turn->stack_a = NULL;
	turn->stack_b = NULL;
	*ac = *ac - turn->options_length;
	*av = *av + turn->options_length;
}

static int	free_turn(t_turn *turn)
{
	stack_del_content(turn->stack_a);
	stack_del_content(turn->stack_b);
	ft_memdel((void **)&(turn->visualizator));
	return (0);
}

int	main(int ac, char **av)
{
	t_turn			turn;
	t_stack			stack_a;
	t_stack			stack_b;
	t_visualiser	visualiser;

	init_turn(&turn, &visualiser, &ac, &av);
	if (ac < 2)
		return (free_turn(&turn));
	if (init_stack(&stack_a, ac - 1))
		error(MEMOERROR);
	if (init_stack(&stack_b, ac - 1))
		error(MEMOERROR);
	turn.stack_a = &stack_a;
	turn.stack_b = &stack_b;
	check_args(&turn, ac, av);
	if (is_sorted(&stack_a))
		return (0);
	if (is_option_activated(turn.visualizator->options, V_OPTION))
		init_visualiser(turn.visualizator);
	if (ac <= 6)
		simple_sort(&turn);
	else
		push_b(&turn, 0, stack_a.length - 1);
	if (is_option_activated(turn.visualizator->options, V_OPTION))
		loop_program(turn.visualizator);
	return (free_turn(&turn));
}
