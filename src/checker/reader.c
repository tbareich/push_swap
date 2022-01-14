/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:58:48 by tbareich          #+#    #+#             */
/*   Updated: 2022/01/14 12:43:37 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void		reader(t_turn *turn, int ac, char **av)
{
	char 				*line;
	int					gnl_sign;
	e_operation			operation;
	 
	check_args(turn ,ac, av);
	line = NULL;
	while ((gnl_sign = get_next_line(0, &line)) > 0)
	{
		operation = check_opt(line);
		if (operation == unkonwn)
			error(DEFAULTERROR);
		run_action(turn, operation, 0);
		ft_strdel(&line);
		line = NULL;
	}
	if (gnl_sign < 0)
		error(DEFAULTERROR);
}