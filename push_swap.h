/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:58:35 by tbareich          #+#    #+#             */
/*   Updated: 2022/01/02 00:58:35 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <ft_printf.h>

enum				e_operation
{
	unkonwn,
	sa,
	sb,
	ss,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
	pa,
	pb
};

void				check_args(int ac, char **av);
void				error(char *msg);
void				reader(int ac, char **av);
enum e_operation	check_opt(char *opt);


#endif