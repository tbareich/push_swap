/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 21:40:46 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/16 12:27:05 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_operation	check_opt(char *opt)
{
	if (ft_strcmp(opt, "sa") == 0)
		return (sa);
	else if (ft_strcmp(opt, "sb") == 0)
		return (sb);
	else if (ft_strcmp(opt, "ss") == 0)
		return (ss);
	else if (ft_strcmp(opt, "pa") == 0)
		return (pa);
	else if (ft_strcmp(opt, "pb") == 0)
		return (pb);
	else if (ft_strcmp(opt, "ra") == 0)
		return (ra);
	else if (ft_strcmp(opt, "rb") == 0)
		return (rb);
	else if (ft_strcmp(opt, "rr") == 0)
		return (rr);
	else if (ft_strcmp(opt, "rra") == 0)
		return (rra);
	else if (ft_strcmp(opt, "rrb") == 0)
		return (rrb);
	else if (ft_strcmp(opt, "rrr") == 0)
		return (rrr);
	return (unkonwn);
}
