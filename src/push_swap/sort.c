/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:16:39 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/05 16:21:05 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	print_rev(t_turn *turn, t_list *list)
{
	if (list->next != NULL)
		print_rev(turn, list->next);
	++turn->visualizator->turn;
	print_action(turn, *((t_operation *)list->content));
}

void	start_sort(t_turn *turn, t_stack *stack_a,
	t_action_list *best_actions, int ac)
{
	if (is_sorted(*turn))
		return ;
	else
	{
		setvbuf(stdout, NULL, _IONBF, 0);
		if (ac == 4 || ac == 6 || ac == 3)
		{
			turn->stack_a = copy_stack(*stack_a);
			simple_sort(turn);
			stack_del(&(turn->stack_a));
		}
		else
			*best_actions = best_actions_list(turn, *stack_a);
		turn->stack_a = stack_a;
		if (best_actions->length == 0)
			print_rev(turn, turn->actions->head);
		else
			print_rev(turn, best_actions->head);
		ft_lstdel(&(best_actions->head), ft_delcontent);
	}
	if (is_option_activated(turn->visualizator->options, V_OPTION))
		loop_program(turn->visualizator);
	stack_del_content(stack_a);
}
