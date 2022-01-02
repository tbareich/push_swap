/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:58:48 by tbareich          #+#    #+#             */
/*   Updated: 2022/01/02 01:57:41 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	reader(int ac, char **av)
{
	char 	*line;
	int		gnl_sign;

	check_args(ac, av);
	line = NULL;
	while ((gnl_sign = get_next_line(0, &line)) > 0)
	{
		if (check_opt(line) == unkonwn)
			error("ERROR");
		ft_strdel(&line);
		line = NULL;
	}
	ft_printf("%d\n", gnl_sign);

	if (gnl_sign < 0)
		error("ERROR");
}