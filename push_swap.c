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

t_stack		*copy_stack(t_stack stack)
{
	t_stack	*copy;
	int		i;

	copy = malloc(sizeof(t_stack));
	init_stack(copy, stack.length);
	i = 0;
	while (i < stack.top)
	{
		push_stack(copy, stack.array[i]);
		++i;
	}
	return copy;
}

void		print_rev(t_list list)
{
	if (list.next != NULL)
		print_rev(*(list.next));
	ft_putendl(list.content);
}

int			main(int ac, char **av)
{
	t_turn	turn;
	t_stack			stack_a;
	t_stack			stack_b;
	t_action_list	a_actions;
	t_action_list	b_actions;
	t_action_list	actions;
	int				i;
	int				best_turns;
	t_action_list	best_actions;

	if (init_stack(&stack_a, ac - 1))
		error(MEMOERROR);
	if (init_stack(&stack_b, ac - 1))
		error(MEMOERROR);
	turn.stack_b = &stack_b;
	turn.stack_a = &stack_a;
	turn.b_actions = &a_actions;
	turn.a_actions = &b_actions;
	turn.actions = &actions;
	turn.b_actions->head = NULL;
	turn.a_actions->head = NULL;
	turn.actions->head = NULL;
	turn.actions->length = 0;
	best_actions.head = NULL;
	best_actions.length = 0;
	if (ac < 2)
		return (0);
	check_args(&turn ,ac, av);
	if (is_sorted(turn))
		return (0);
	else
	{
		if (ac == 4 || ac == 6 || ac == 3)
			simple_sort(&turn);
		else
		{
			if (ac <= 101)
				i = ac / 4;
			else
				i = 20;
			turn.low_min = 0;
			turn.low_max = i;
			turn.up_min = 0;
			turn.up_max = i;
			best_turns = MAX_INT;
			while (i >= 0)
			{
				turn.stack_a = copy_stack(stack_a);
				sort_by_chanks(&turn, stack_a.top);
				while (stack_b.top)
					run_action(&turn, pa, 1);
				if (actions.length < best_turns)
				{
					ft_lstdel(&(best_actions.head), ft_delcontent);
					best_actions.head = actions.head;
					best_actions.length = actions.length;
					best_turns = actions.length;
					actions.head = NULL;
					actions.length = 0;
				}
				else
				{
					ft_lstdel(&(actions.head), ft_delcontent);
					actions.length = 0;
				}

				// if (best_turns < 5500)
				// 	break ;
				--turn.low_max;
				++turn.up_min;
				// turn.up_max+=2;
				--i;
			}

		}
		print_rev(*(best_actions.head));
		ft_lstdel(&(best_actions.head), ft_delcontent);
		ft_lstdel(&(actions.head), ft_delcontent);
	}
	return (0);
}