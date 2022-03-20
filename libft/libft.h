/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 18:42:33 by tbareich          #+#    #+#             */
/*   Updated: 2019/09/27 00:17:56 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

/*
 ** definitions
 ** --------
*/

# define LIBFT_H

# define ARRLST_SIZE 4
# define BUFF_SIZE 5
# define MAX_INT 2147483647
# define MIN_INT -2147483648

/*
 ** includes
 ** --------
*/

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

/*
 ** structures
 ** ----------
*/

typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}	t_list;

typedef struct s_bst
{
	int				key;
	void			*content;
	size_t			content_size;
	struct s_bst	*left;
	struct s_bst	*right;
}	t_bst;

typedef struct s_arrlst
{
	unsigned int	length;
	void			**array;
}	t_arrlst;

typedef struct s_stack_element
{
	int	value;
	int	keep;
}	t_stack_element;

typedef struct s_stack
{
	int				top;
	int				length;
	t_stack_element	*array;
}	t_stack;

typedef struct s_range
{
	int	min;
	int	max;
}	t_range;

/*
 ** libc Functions
 ** --------------
*/

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *hay, const char *needl, size_t len);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
 ** Memory Functions
 ** --------------
*/

void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_bzero(void *s, size_t n);

/*
 ** Linked List Functions
 ** ---------------------
*/

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_delcontent(void *content, size_t content_size);
void				ft_lstpush(t_list **alst, t_list *new);
t_list				*ft_lstpop(t_list **alst);
void				ft_putlst(t_list *lst);
void				ft_lstaddat(t_list **alst, t_list *new, int index);
t_list				*ft_lstdelat(t_list **alst, int index);
t_list				*ft_lstshift(t_list **alst);
int					ft_lstlen(t_list *lst);

/*
 ** Binary Search Functions
 ** -----------------------
*/

t_bst				*bst_find(t_bst *root, int key);
t_bst				*bst_newnode(int key, void *content, size_t content_size);
t_bst				*bst_insert(t_bst *root, t_bst *node);
t_bst				*bst_deletenode(t_bst *root, int key);
t_bst				*bst_min(t_bst *root);
t_bst				*bst_max(t_bst *root);
void				bst_delete(t_bst *root);
void				bst_inorder(t_bst *root);
int					bst_modify_addr(t_bst *node, void *content,
						size_t content_size);

/*
 ** Binary Search Functions
 ** -----------------------
*/

t_arrlst			*arrlst_create(int size);
void				arrlst_add(t_arrlst **arrlst, void *elm);
void				arrlst_copy(t_arrlst *old_arr, t_arrlst *new_arr);
void				arrlst_del(t_arrlst **arrlst);
int					arrlst_size(t_arrlst arrlst);

/*
 ** Stack Functions
 ** -----------------------
*/

char				init_stack(t_stack *stack, int length);
char				push_stack(t_stack *stack, int element, int keep);
t_stack_element		*pop_stack(t_stack *stack);
void				stack_del(t_stack **stack);
void				stack_del_content(t_stack *stack);

/*
 ** Math Functions
 ** -----------------------
*/

unsigned int		ft_abs(int num);
unsigned long		ft_labs(long num);
unsigned long long	ft_llabs(long long num);
int					max(int a, int b);
int					min(int a, int b);
char				ft_between(int v, int min, int max);
int					ft_modulo(int i, int j);
int					ft_convert_range(int value, t_range old_range,
						t_range new_range);

/*
 ** Extra Functions
 ** -----------------------
*/

char				is_int(char *number);
void				error(char *msg);
char				*ft_strjoin_free(char const *s1, char const *s2,
						int option);
char				*ft_strdup_free(char **s1);
void				*ft_realloc(void *ptr, size_t pre_size, size_t size);
void				ft_swap(t_stack_element *elem1, t_stack_element *elem2);
int					get_int_len(int nbr);
int					get_next_line(const int fd, char **line);

#endif
