/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 04:39:59 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/08 22:05:02 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

const char	*g_actions[12]
	= {NULL, "sa", "sb", "ss", "ra", "rb", "rr",
	"rra", "rrb", "rrr", "pa", "pb"};

void	run_action(t_turn *turn, t_operation operation, char append)
{
	if (operation == sa)
		sx(turn->stack_a);
	else if (operation == sb)
		sx(turn->stack_b);
	else if (operation == ss)
		s_a_b(turn->stack_a, turn->stack_b);
	else if (operation == pa)
		px(turn->stack_a, turn->stack_b);
	else if (operation == pb)
		px(turn->stack_b, turn->stack_a);
	else if (operation == ra)
		rx(turn->stack_a);
	else if (operation == rb)
		rx(turn->stack_b);
	else if (operation == rr)
		r_a_b(turn->stack_a, turn->stack_b);
	else if (operation == rra)
		rrx(turn->stack_a);
	else if (operation == rrb)
		rrx(turn->stack_b);
	else if (operation == rrr)
		rr_a_b(turn->stack_a, turn->stack_b);
	if (operation != unkonwn && append == 1)
	{
		ft_putendl(g_actions[operation]);
		++turn->visualizator->turn;
		if (is_option_activated(turn->visualizator->options, V_OPTION))
			draw(turn->visualizator, *(turn->stack_a), *(turn->stack_b));
	}
}

void run_naction(t_turn *turn, t_operation operation, int length)
{
	while (length--)
		run_action(turn, operation, 1);	
}

void	print_action(t_turn *turn, t_operation operation)
{
	run_action(turn, operation, 0);
	if (g_actions[operation] != NULL)
	{
		if (is_option_activated(turn->visualizator->options, V_OPTION) == 1)
			draw(turn->visualizator, *(turn->stack_a), *(turn->stack_b));
		ft_putendl(g_actions[operation]);
	}
}
