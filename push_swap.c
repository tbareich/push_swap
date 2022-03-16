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

static int set_options(t_visualizator *visualizator, int ac, char **av)
{
	int i;
	int options_length;

	i = 1;
	options_length = 0;
	while (i < ac)
	{
		if (ft_strequ(av[i], "-v"))
		{
			visualizator->options |= 1;
			++options_length;
		}
		else if (ft_strequ(av[i], "-c"))
		{
			visualizator->options |= 2;
			++options_length;
		}
		++i;
	}
	return (options_length);
}

static void init_turn(t_turn **turn, int ac, char **av)
{
	*turn = malloc(sizeof(t_turn));
	if (*turn == NULL)
		error(MEMOERROR);
	(*turn)->actions = (t_action_list *)ft_memalloc(sizeof(t_action_list));
	if ((*turn)->actions == NULL)
		error(MEMOERROR);
	(*turn)->a_actions = (t_action_list *)ft_memalloc(sizeof(t_action_list));
	if ((*turn)->a_actions == NULL)
		error(MEMOERROR);
	(*turn)->b_actions = (t_action_list *)ft_memalloc(sizeof(t_action_list));
	if ((*turn)->b_actions == NULL)
		error(MEMOERROR);
	(*turn)->visualizator = (t_visualizator *)malloc(sizeof(t_visualizator));
	if ((*turn)->visualizator == NULL)
		error(MEMOERROR);
	(*turn)->visualizator->turn = 0;
	(*turn)->visualizator->options = 0;
	(*turn)->options_length = set_options((*turn)->visualizator, ac, av);
	(*turn)->low_min = 0;
	(*turn)->low_max = MAXRETRY;
	(*turn)->up_min = 0;
	(*turn)->up_max = MAXRETRY;
	(*turn)->stack_a = NULL;
	(*turn)->stack_b = NULL;
	(*turn)->b_rotate_length = 0;
	(*turn)->a_rotate_length = 0;
}

static int free_turn(t_turn **turn)
{
	stack_del_content((*turn)->stack_a);
	stack_del_content((*turn)->stack_b);
	ft_lstdel(&((*turn)->actions->head), ft_delcontent);
	ft_memdel((void **)&((*turn)->a_actions));
	ft_memdel((void **)&((*turn)->b_actions));
	ft_memdel((void **)&((*turn)->actions));
	ft_memdel((void **)&((*turn)->visualizator));
	ft_memdel((void **)turn);
	return (0);
}

int main(int ac, char **av)
{
	t_turn *turn;
	t_stack stack_a;
	t_stack stack_b;

	init_turn(&turn, ac, av);
	ac = ac - turn->options_length;
	av = av + turn->options_length;
	if (ac < 2)
		return (free_turn(&turn));
	if (init_stack(&stack_a, ac - 1))
		error(MEMOERROR);
	if (init_stack(&stack_b, ac - 1))
		error(MEMOERROR);
	turn->stack_a = &stack_a;
	turn->stack_b = &stack_b;
	check_args(turn, ac, av);
	if (is_sorted(&stack_a))
		return (0);
	if (is_option_activated(turn->visualizator->options, V_OPTION))
		init_visualisator(turn->visualizator);
	if (ac == 4 || ac == 6 || ac == 3)
		simple_sort(turn);
	push_b(turn, 0, stack_a.length - 1);
	if (is_option_activated(turn->visualizator->options, V_OPTION))
		loop_program(turn->visualizator);
	return (free_turn(&turn));
}
