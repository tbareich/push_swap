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
	int		number_index;

	if (init_stack(&stack_a, ac - 1))
		error(MEMOERROR);
	if (init_stack(&stack_b, ac - 1))
		error(MEMOERROR);
	if (ac < 2)
		return (0);
	turn.stack_a = &stack_a;
	turn.stack_b = &stack_b;
	check_args(&turn ,ac, av);
	chanks_divide(&turn, ac - 1);
	while (stack_b.top)
	{
		number_index = find_max(&stack_b);
		if (number_index != -1)
			move_to_top(&stack_b, 'b', number_index);	
		px(&stack_a, &stack_b);
		ft_putendl("pa");
	}
	return (0);
}