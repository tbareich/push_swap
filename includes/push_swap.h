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
# include <visualiser.h>

# ifndef MEMOERROR
#  define MEMOERROR "INSUFFICIENT MEMORY\n"
# endif

# ifndef DEFAULTERROR
#  define DEFAULTERROR "ERROR\n"
# endif

# define MAXRETRY 20

# ifndef V_OPTION
#  define V_OPTION 0
# endif

# ifndef C_OPTION
#  define C_OPTION 1
# endif

# define H_OPTION 2

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

typedef enum e_stack_range
{
	none,
	upper_half,
	lower_half
}	t_stack_range;

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
	t_visualiser	visualizator;
	int				current_turn;
	int				options_length;
}	t_turn;

typedef struct s_indexing
{
	unsigned int	index;
	int				value;
}	t_indexing;

/*
**	checker functions
*/
void				reader(t_turn *turn, int ac, char **av);
t_operation			check_opt(char *opt);

/*
**	push_swap functions
*/
void				simple_sort(t_turn *turn);
char				is_sorted_dir_a(t_turn *turn, int left, int right, int dir);
char				is_sorted_dir_b(t_turn *turn, int left, int right, int dir);
void				move_to_top(t_turn *turn, char stack_name,
						int index);
char				is_min_max(t_stack *stack, int value);
int					find_min(t_stack *stack);
int					is_a_sorted(t_turn *turn, int left, int right);
int					is_b_sorted(t_turn *turn, int left, int right);
void				push_b(t_turn *turn, int left, int right);
void				push_a(t_turn *turn, int left, int right);
void				sort_b(t_turn *turn, int left, int right, int dist);
void				sort_b_three(t_turn *turn, int left, int right, int dist);
void				sort_a(t_turn *turn, int left, int right);
void				sort_a_three(t_turn *turn, int left, int right);
void				sort_a_two(t_turn *turn, int right);
int					find_middle_spot_a(t_stack *stack, int number);

/*
**	operations functions
*/
void				sx(t_stack *stack);
void				s_a_b(t_stack *stack1, t_stack *stack2);
void				px(t_stack *destination_stack, t_stack *source_stack);
void				rx(t_stack *stack);
void				r_a_b(t_stack *stack1, t_stack *stack2);
void				rrx(t_stack *stack);
void				rr_a_b(t_stack *stack1, t_stack *stack2);

/*
**	shared functions
*/
void				error(t_turn *turn, char *msg);
void				check_args(t_turn *turn, int ac, char **av);
void				merge_sort(t_list **headRef);
char				is_sorted(t_stack *stack);
void				run_action(t_turn *turn, t_operation operation,
						char add_action);
int					free_turn(t_turn *turn);

#endif