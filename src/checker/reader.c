/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:58:48 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/09 12:35:13 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	reader(t_turn *turn, int ac, char **av)
{
	char				*line;
	int					gnl_sign;
	e_operation			operation;

	check_args(turn, ac, av);
	line = NULL;
	gnl_sign = get_next_line(0, &line);
	while (gnl_sign > 0)
	{
		operation = check_opt(line);
		if (operation == unkonwn)
			error(DEFAULTERROR);
		ft_printf("%s\n",line);
		run_action(turn, operation, 0);
		ft_strdel(&line);
		line = NULL;
		gnl_sign = get_next_line(0, &line);
	}
	if (gnl_sign < 0)
		error(DEFAULTERROR);
}
