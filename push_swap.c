/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:58:31 by tbareich          #+#    #+#             */
/*   Updated: 2022/01/02 00:58:31 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>


int	main(int ac, char **av)
{
	t_turn	turn;
	t_stack	stack_a;
	t_stack	stack_b;

	if (new_from_stack(&stack_a, ac - 1))
		error("Insufficient memory A");
	if (new_from_stack(&stack_b, ac - 1))
		error("Insufficient memory B");
	check_args(&turn ,ac, av);
	return (0);
}