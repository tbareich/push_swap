/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:58:48 by tbareich          #+#    #+#             */
/*   Updated: 2022/01/03 19:12:11 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	reader(t_turn *turn, int ac, char **av)
{
	char 	*line;
	int		gnl_sign;
	 
	check_args(turn ,ac, av);
	line = NULL;
	while ((gnl_sign = get_next_line(0, &line)) > 0)
	{
		if (check_opt(line) == unkonwn)
			error("ERROR");
		ft_strdel(&line);
		line = NULL;
	}
	if (gnl_sign < 0)
		error("ERROR");
}