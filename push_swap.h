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

# ifndef MEMOERROR
# define MEMOERROR "INSUFFICIENT MEMORY\n"
# endif

# ifndef DEFAULTERROR
# define DEFAULTERROR "ERROR\n"
# endif

enum				e_operation
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
};

typedef struct		s_turn
{
	t_stack *stack_a;
	t_stack *stack_b;
}					t_turn;

typedef struct		s_indexing
{
	unsigned	index;
	int			value;
}					t_indexing;

void				reader(t_turn *turn, int ac, char **av);
void				check_args(t_turn *turn, int ac, char **av);
enum e_operation	check_opt(char *opt);
void 				merge_sort(t_list **headRef);
void				print_sorted_list(t_list *head);
char				is_sorted(t_turn turn);
void				chanks_divide(t_turn *turn, int length);
int					search_in_range(t_turn *turn, int chank);
void				move_to_top(t_stack *stack_a, char stack_name, int index);
void				find_best_spot(t_turn *turn, int number);
char				is_min_max(t_stack *stack_b, int value);
int					find_min(t_stack *stack_b);


void				sx(t_stack *stack);
void				s_a_b(t_stack *stack1, t_stack *stack2);
void				px(t_stack *destination_stack, t_stack *source_stack);
void				rx(t_stack *stack);
void				r_a_b(t_stack *stack1, t_stack *stack2);
void				rrx(t_stack *stack);
void				rr_a_b(t_stack *stack1, t_stack *stack2);

#endif