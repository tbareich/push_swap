/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 04:39:59 by tbareich          #+#    #+#             */
/*   Updated: 2022/02/14 22:49:36 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

const char	*g_actions[12]
	= {NULL, "sa", "sb", "ss", "ra", "rb", "rr",
	"rra", "rrb", "rrr", "pa", "pb"};

static void	add_action(t_turn *turn, e_operation operation)
{
	if (operation != unkonwn)
	{
		ft_lstadd(&(turn->actions->head),
			ft_lstnew(&operation, sizeof(e_operation)));
		turn->actions->length++;
	}
}

void	run_action(t_turn *turn, e_operation operation, char append)
{
	if (operation == sa)
		sx(turn->stack_a);
	else if (operation == sb)
		sx(turn->stack_b);
	else if (operation == ss)
		s_a_b(turn->stack_a, turn->stack_b);
	else if (operation == pa)
		px(turn->stack_a, turn->stack_b);
	else if (operation == pb)
		px(turn->stack_b, turn->stack_a);
	else if (operation == ra)
		rx(turn->stack_a);
	else if (operation == rb)
		rx(turn->stack_b);
	else if (operation == rr)
		r_a_b(turn->stack_a, turn->stack_b);
	else if (operation == rra)
		rrx(turn->stack_a);
	else if (operation == rrb)
		rrx(turn->stack_b);
	else if (operation == rrr)
		rr_a_b(turn->stack_a, turn->stack_b);
	if (operation != unkonwn && append == 1)
		add_action(turn, operation);
}

void	print_action(t_turn *turn, e_operation operation)
{
	run_action(turn, operation, 0);
	if (g_actions[operation] != NULL)
	{
		if (is_option_activated(turn->visualizator->options, V_OPTION) == 1)
			draw(turn->visualizator, *(turn->stack_a), *(turn->stack_b));
		ft_putendl(g_actions[operation]);
	}
}

void	add_lst_actions(t_turn *turn)
{
	t_list		*a_lst;
	t_list		*b_lst;
	e_operation	a_operation;
	e_operation	b_operation;

	a_lst = turn->a_actions->head;
	b_lst = turn->b_actions->head;
	while (a_lst && b_lst)
	{
		a_operation = *((e_operation *)(a_lst->content));
		if (a_operation == pb)
			break ;
		b_operation = *((e_operation *)(b_lst->content));
		if (a_operation == ra && b_operation == rb)
			add_action(turn, rr);
		else if (a_operation == rra && b_operation == rrb)
			add_action(turn, rrr);
		else if (a_operation == sa && b_operation == sb)
			add_action(turn, ss);
		else
		{
			add_action(turn, b_operation);
			add_action(turn, a_operation);
		}
		a_lst = a_lst->next;
		b_lst = b_lst->next;
		ft_lstdelone(&(turn->a_actions->head), ft_delcontent);
		ft_lstdelone(&(turn->b_actions->head), ft_delcontent);
		turn->a_actions->head = a_lst;
		turn->b_actions->head = b_lst;
	}
	while (b_lst)
	{
		b_operation = *((e_operation *)(b_lst->content));
		add_action(turn, b_operation);
		b_lst = b_lst->next;
		ft_lstdelone(&(turn->b_actions->head), ft_delcontent);
		turn->b_actions->head = b_lst;
	}
	while (a_lst)
	{
		a_operation = *((e_operation *)(a_lst->content));
		add_action(turn, a_operation);
		a_lst = a_lst->next;
		ft_lstdelone(&(turn->a_actions->head), ft_delcontent);
		turn->a_actions->head = a_lst;
	}
}
