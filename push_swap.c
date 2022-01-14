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

static int	set_options(t_visualization *visualizator, int ac, char **av)
{
	int		i;
	int		options_length;

	i = 1;
	options_length = 0;
	while (i < ac && i < 3)
	{
		if (ft_strequ(av[i], "-v"))
		{
			visualizator->options |= 1;
			++options_length;
		}
		else if (ft_strequ(av[i], "-c"))
		{
			visualizator->options |= 2;
			++options_length;
		}	
		++i;
	}
	return (options_length);
}

int			main(int ac, char **av)
{
	t_turn	turn;
	t_stack	stack_a;
	t_stack	stack_b;
	t_visualization visualizator;
	int				options_length;

	if (init_stack(&stack_a, ac - 1))
		error(MEMOERROR);
	if (init_stack(&stack_b, ac - 1))
		error(MEMOERROR);
	turn.stack_b = &stack_b;
	turn.stack_a = &stack_a;
	turn.b_actions = NULL;
	turn.a_actions = NULL;
	turn.visualizator = &visualizator;
	options_length = set_options(&visualizator, ac, av);
	ac = ac - options_length;
	av =  av + options_length;
	if (ac < 2)
		return (0);
	check_args(&turn ,ac, av);
	if (is_option_activated(visualizator.options, V_OPTION))
		init_visualizator(&visualizator);
	if (is_sorted(turn))
		return (0);
	if (ac == 3)
		run_action(&turn, sa, 1);
	else
	{
		if (ac <= 100)
			sort_by_chanks(&turn, 5, stack_a.top);
		else
			sort_by_chanks(&turn, 11, stack_a.top);
		while (stack_b.top)
			run_action(&turn, pa, 1);
	}
	if (is_option_activated(visualizator.options, V_OPTION))
		loop_program(&visualizator);
	return (0);
}