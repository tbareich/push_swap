/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 04:39:59 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/22 18:20:32 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	display_operation(t_data *data, t_operation operation)
{
	const static char	*g_actions[12] = {NULL, "sa", "sb", "ss", "ra", "rb",
		"rr", "rra", "rrb", "rrr", "pa", "pb"};

	ft_putendl(g_actions[operation]);
	++data->visualizator.turn;
	if (is_option_activated(data->visualizator.options, V_OPTION))
		draw(&(data->visualizator), *(data->stack_a), *(data->stack_b));
}

void	run_action(t_data *data, t_operation operation, char append)
{
	if (operation == sa)
		sx(data->stack_a);
	else if (operation == sb)
		sx(data->stack_b);
	else if (operation == ss)
		s_a_b(data->stack_a, data->stack_b);
	else if (operation == pa)
		px(data->stack_a, data->stack_b);
	else if (operation == pb)
		px(data->stack_b, data->stack_a);
	else if (operation == ra)
		rx(data->stack_a);
	else if (operation == rb)
		rx(data->stack_b);
	else if (operation == rr)
		r_a_b(data->stack_a, data->stack_b);
	else if (operation == rra)
		rrx(data->stack_a);
	else if (operation == rrb)
		rrx(data->stack_b);
	else if (operation == rrr)
		rr_a_b(data->stack_a, data->stack_b);
	if (operation != unkonwn && append == 1)
		display_operation(data, operation);
}
