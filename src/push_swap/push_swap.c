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

static void	init_data(t_data *data, int *ac, char ***av)
{
	data->visualizator.options = 0;
	data->options_length = set_options(&(data->visualizator), *ac, *av);
	data->visualizator.turn = 0;
	*ac = *ac - data->options_length;
	*av = *av + data->options_length;
}

int	main(int ac, char **av)
{
	t_data			data;
	t_stack			stack_a;
	t_stack			stack_b;

	init_data(&data, &ac, &av);
	if (ac < 2)
		return (free_data(&data));
	data.stack_a = &stack_a;
	data.stack_b = &stack_b;
	if (init_stack(data.stack_a, ac - 1))
		error(&data, MEMOERROR);
	if (init_stack(data.stack_b, ac - 1))
		error(&data, MEMOERROR);
	check_args(&data, ac, av);
	if (is_sorted(&stack_a))
		return (free_data(&data));
	if (is_option_activated(data.visualizator.options, V_OPTION))
		init_visualiser(&(data.visualizator));
	if (ac <= 6)
		simple_sort(&data);
	else
		push_b(&data, 0, stack_a.length - 1);
	if (is_option_activated(data.visualizator.options, V_OPTION))
		loop_program(&(data.visualizator));
	return (free_data(&data));
}
