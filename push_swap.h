/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:58:35 by tbareich          #+#    #+#             */
/*   Updated: 2022/01/02 00:58:35 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <ft_printf.h>
# include <visualisator.h>

# ifndef MEMOERROR
# define MEMOERROR "INSUFFICIENT MEMORY\n"
# endif

# ifndef DEFAULTERROR
# define DEFAULTERROR "ERROR\n"
# endif

typedef enum				
{
	unkonwn,
	sa,
	sb,
	ss,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
	pa,
	pb
}					e_operation;

typedef struct		s_turn
{
	t_stack *stack_a;
	t_stack *stack_b;
	int			a_rotate_length;
	e_operation a_rotate_type;
	t_list	*a_actions;
	t_list	*b_actions;
	t_visualization	*visualizator;
}					t_turn;

typedef struct		s_indexing
{
	unsigned	index;
	int			value;
}					t_indexing;

void				reader(t_turn *turn, int ac, char **av);
void				check_args(t_turn *turn, int ac, char **av);
e_operation			check_opt(char *opt);
void 				merge_sort(t_list **headRef);
void				print_sorted_list(t_list *head);
char				is_sorted(t_turn turn);
void				sort_by_chanks(t_turn *turn , int divider, int length);
int					search_in_range(t_turn *turn, int chank);
void				move_to_top_a_optimized(t_turn *turn, int index);
void				move_to_top_b_optimized(t_turn *turn, int index);
void				move_to_top(t_turn *turn, char stack_name,
									int index);
char				is_min_max(t_stack *stack, int value);
void				run_action(t_turn *turn, e_operation operation,
									char print_action);
void				add_action(t_list **actions_list, e_operation operation);
void				print_lst_actions(t_turn *turn);
void				find_middle_spot_a(t_turn *turn, t_stack *stack, int number);
void				find_middle_spot_b(t_turn *turn, t_stack *stack, int number);
int					find_max(t_stack *stack);
int					find_min(t_stack *stack);
void				simple_sort(t_turn *turn);

void				sx(t_stack *stack);
void				s_a_b(t_stack *stack1, t_stack *stack2);
void				px(t_stack *destination_stack, t_stack *source_stack);
void				rx(t_stack *stack);
void				r_a_b(t_stack *stack1, t_stack *stack2);
void				rrx(t_stack *stack);
void				rr_a_b(t_stack *stack1, t_stack *stack2);

#endif