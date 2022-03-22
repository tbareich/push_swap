/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:58:48 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/22 18:17:31 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	reader(t_data *data, int ac, char **av)
{
	char				*line;
	int					gnl_sign;
	t_operation			operation;

	check_args(data, ac, av);
	line = NULL;
	gnl_sign = get_next_line(0, &line);
	while (gnl_sign > 0)
	{
		operation = check_opt(line);
		if (operation == unkonwn)
			error(data, DEFAULTERROR);
		run_action(data, operation, 0);
		ft_strdel(&line);
		line = NULL;
		gnl_sign = get_next_line(0, &line);
	}
	if (gnl_sign < 0)
		error(data, DEFAULTERROR);
}
