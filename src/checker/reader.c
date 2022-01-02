/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:58:48 by tbareich          #+#    #+#             */
/*   Updated: 2022/01/02 18:44:42 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	reader(int ac, char **av)
{
	char 	*line;
	int		gnl_sign;
	int		invalid_opt;

	invalid_opt = 0;
	check_args(ac, av);
	line = NULL;
	while ((gnl_sign = get_next_line(0, &line)) > 0)
	{
		if (check_opt(line) == unkonwn)
			invalid_opt = 1;
		ft_strdel(&line);
		line = NULL;
	}
	if (gnl_sign < 0 || invalid_opt)
		error("ERROR");
}