/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:58:27 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/22 18:17:21 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int ac, char **av)
{
	t_data	data;
	t_stack	stack_a;
	t_stack	stack_b;

	if (ac < 2)
		return (0);
	if (init_stack(&stack_a, ac - 1))
		error(&data, MEMOERROR);
	if (init_stack(&stack_b, ac - 1))
		error(&data, MEMOERROR);
	data.stack_a = &stack_a;
	data.stack_b = &stack_b;
	reader(&data, ac, av);
	if (is_sorted(data.stack_a))
		ft_putendl("OK");
	else
		ft_putendl("KO");
	stack_del_content(&stack_a);
	stack_del_content(&stack_b);
}
