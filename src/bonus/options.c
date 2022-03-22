/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 20:34:18 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/22 18:15:10 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<visualiser.h>

char	is_option_activated(char option, int option_index)
{
	return ((option >> option_index) & 1);
}

int	set_options(t_visualiser *visualizator, int ac, char **av)
{
	int	i;
	int	options_length;

	i = 1;
	options_length = 0;
	while (i < ac)
	{
		if (ft_strequ(av[i], "-h"))
		{
			visualizator->options |= 1;
			++options_length;
		}
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
