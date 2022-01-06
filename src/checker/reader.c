/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:58:48 by tbareich          #+#    #+#             */
/*   Updated: 2022/01/06 10:38:27 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	run_operation(t_turn *turn, enum e_operation operation)
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
}

void		reader(t_turn *turn, int ac, char **av)
{
	char 				*line;
	int					gnl_sign;
	enum e_operation	opt;
	 
	check_args(turn ,ac, av);
	line = NULL;
	while ((gnl_sign = get_next_line(0, &line)) > 0)
	{
		opt = check_opt(line);
		if (opt == unkonwn)
			error(DEFAULTERROR);
		run_operation(turn, opt);
		ft_strdel(&line);
		line = NULL;
	}
	if (gnl_sign < 0)
		error(DEFAULTERROR);
}