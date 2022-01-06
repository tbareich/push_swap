/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:58:27 by tbareich          #+#    #+#             */
/*   Updated: 2022/01/06 11:59:46 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	is_sorted(t_turn turn)
{
	int		i;

	if (turn.stack_b->top != 0)
	{
		ft_putstr("KO\n");
		return ;
	}
	i = turn.stack_a->top - 1;
	while (i > 0)
	{
		if (turn.stack_a->array[i] >= turn.stack_a->array[i - 1])
		{
			ft_putstr("KO\n");
			return ;
		}
		--i;
	}
	ft_putstr("OK\n");
}

int			main(int ac, char **av)
{
	t_turn	turn;
	t_stack	stack_a;
	t_stack	stack_b;

	if (init_stack(&stack_a, ac - 1))
		error(MEMOERROR);
	if (init_stack(&stack_b, ac - 1))
		error(MEMOERROR);
	turn.stack_a = &stack_a;
	turn.stack_b = &stack_b;
	reader(&turn, ac, av);
	// print_stack(&stack_a);
	// print_stack(&stack_b);
	is_sorted(turn);
}