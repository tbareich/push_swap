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

	if (init_stack(&stack_a, ac - 1))
		error(MEMOERROR);
	if (init_stack(&stack_b, ac - 1))
		error(MEMOERROR);
	if (ac < 2)
		return (0);
	turn.stack_a = &stack_a;
	turn.stack_b = &stack_b;
	check_args(&turn ,ac, av);
	// print_stack(turn.stack_a);
	chanks_divide(&turn, ac - 1);
	// print_stack(turn.stack_b);
	while (stack_b.top)
	{
		px(&stack_a, &stack_b);
	}
	print_stack(turn.stack_a);
	return (0);
}