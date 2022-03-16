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
# define PUSH_SWAP_H

# include <libft.h>
# include <visualisator.h>

# ifndef MEMOERROR
#  define MEMOERROR "INSUFFICIENT MEMORY\n"
# endif

# ifndef DEFAULTERROR
#  define DEFAULTERROR "ERROR\n"
# endif

# define MAXRETRY 20
# define ft_between(v, min, max) (v >= min && v <= max)

typedef enum e_operation
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
}	t_operation;

typedef enum e_range
{
	none,
	upper_half,
	lower_half
}	t_range;

typedef struct s_action_list
{
	t_list	*head;
	int		length;	
	int		low_min;
	int		low_max;
	int		up_min;
	int		up_max;
}	t_action_list;

typedef struct s_turn
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	t_operation		b_rotate_type;
	t_action_list	*a_actions;
	t_action_list	*b_actions;
	t_action_list	*actions;
	t_visualizator	*visualizator;
	int				b_rotate_length;
	int				a_rotate_length;
	int				low_min;
	int				low_max;
	int				up_min;
	int				up_max;
	int				current_turn;
	int				options_length;
}	t_turn;

typedef struct s_indexing
{
	unsigned int	index;
	int				value;
}	t_indexing;

void				reader(t_turn *turn, int ac, char **av);
void				check_args(t_turn *turn, int ac, char **av);
t_operation			check_opt(char *opt);
void				merge_sort(t_list **headRef);
char				is_sorted(t_stack *stack);
char				is_sorted_dir(t_turn *turn, t_stack *stack, char name, int left, int right, int dir);
int					search_in_range(t_stack *stack, int min, int max);
int					push_best_range(t_turn *turn, t_stack *stack, char name, int min, int max);
void				move_to_top(t_turn *turn, char stack_name,
						int index);
char				is_min_max(t_stack *stack, int value);
void				run_action(t_turn *turn, t_operation operation,
						char add_action);
void				run_naction(t_turn *turn, t_operation operation, int length);
void				simple_sort(t_turn *turn);
int					find_min(t_stack *stack);
void				need_sa(t_turn *turn, t_stack *stack);
void				need_sb(t_turn *turn, t_stack *stack);
int					is_a_sorted(t_turn *turn, int left, int right);
int					is_b_sorted(t_turn *turn, int left, int right);
void				sx(t_stack *stack);
void				s_a_b(t_stack *stack1, t_stack *stack2);
void				px(t_stack *destination_stack, t_stack *source_stack);
void				rx(t_stack *stack);
void				r_a_b(t_stack *stack1, t_stack *stack2);
void				rrx(t_stack *stack);
void				rr_a_b(t_stack *stack1, t_stack *stack2);

void				push_b(t_turn *turn, int left, int right);
void				push_a(t_turn *turn, int left, int right);
t_operation			rotate_a(t_turn *turn, int left, int right,
							t_operation opt);

#endif