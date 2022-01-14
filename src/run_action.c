/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 04:39:59 by tbareich          #+#    #+#             */
/*   Updated: 2022/01/11 12:38:27 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
	
const char	*g_actions[12] = 
	{
		NULL, "sa", "sb", "ss", "ra", "rb", "rr","rra", "rrb", "rrr", "pa", "pb"
	};

void		run_action(t_stack *stack_a, t_stack *stack_b, 
							e_operation operation, char print_action)
{
	if (operation == sa)
		sx(stack_a);
	else if (operation == sb)
		sx(stack_b);
	else if (operation == ss)
		s_a_b(stack_a, stack_b);
	else if (operation == pa)
		px(stack_a, stack_b);
	else if (operation == pb)
		px(stack_b, stack_a);
	else if (operation == ra)
		rx(stack_a);
	else if (operation == rb)
		rx(stack_b);
	else if (operation == rr)
		r_a_b(stack_a, stack_b);
	else if (operation == rra)
		rrx(stack_a);
	else if (operation == rrb)
		rrx(stack_b);
	else if (operation == rrr)
		rr_a_b(stack_a, stack_b);
	if (g_actions[operation] != NULL && print_action == 1)
		ft_putendl(g_actions[operation]);
}

void	print_lst_actions(t_turn *turn)
{
	t_list		*a_lst;
	t_list		*b_lst;
	e_operation a_operation;
	e_operation b_operation;

	a_lst = turn->a_actions;
	b_lst = turn->b_actions;
	while (a_lst && b_lst)
	{
		a_operation = *((e_operation *)(a_lst->content));
		if (a_operation == pb)
			break ;
		b_operation = *((e_operation *)(b_lst->content));
		if (a_operation == ra && b_operation == rb)
			ft_putendl(g_actions[rr]);
		else if (a_operation == rra && b_operation == rrb)
			ft_putendl(g_actions[rrr]);
		else if (a_operation == sa && b_operation == sb)
			ft_putendl(g_actions[ss]);
		else
		{
			ft_putendl(g_actions[b_operation]);
			ft_putendl(g_actions[a_operation]);
		}
		a_lst = a_lst->next;
		b_lst = b_lst->next;
		ft_lstdelone(&(turn->a_actions), ft_delcontent);
		ft_lstdelone(&(turn->b_actions), ft_delcontent);
		turn->a_actions = a_lst;
		turn->b_actions = b_lst;
	}
	while (b_lst)
	{
		b_operation = *((e_operation *)(b_lst->content));
		ft_putendl(g_actions[b_operation]);
		b_lst = b_lst->next;
		ft_lstdelone(&(turn->b_actions), ft_delcontent);
		turn->b_actions = b_lst;
	}
	while (a_lst)
	{
		a_operation = *((e_operation *)(a_lst->content));
		ft_putendl(g_actions[a_operation]);
		a_lst = a_lst->next;
		ft_lstdelone(&(turn->a_actions), ft_delcontent);
		turn->a_actions = a_lst;
	}
}