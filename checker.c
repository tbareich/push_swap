/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:58:27 by tbareich          #+#    #+#             */
/*   Updated: 2022/01/04 02:27:35 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	print(void *elem)
{
	int		*num;

	num = (int *)elem;
	ft_putnbr(*num);
}

int			main(int ac, char **av)
{
	t_turn	turn;
	t_stack	stack_a;
	t_stack	stack_b;

	if (new_from_stack(&stack_a, ac - 1, sizeof(int)))
		error("Insufficient memory");
	if (new_from_stack(&stack_b, ac - 1, sizeof(int)))
		error("Insufficient memory");
	turn.stack_a = stack_a;
	turn.stack_b = stack_b;
	reader(&turn, ac, av);
	print_stack(&stack_a, print);
	print_stack(&stack_b, print);
}