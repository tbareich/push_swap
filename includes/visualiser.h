/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualiser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:02:18 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/20 21:55:05 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALISER_H
# define VISUALISER_H

# include <libft.h>
# include <SDL2/SDL.h>
# include <SDL2/SDL_ttf.h>

# define WIN_W 1500
# define WIN_H 1055
# define STACK_H 1000
# define STACK_W 500

# define V_OPTION 0
# define C_OPTION 1
# define SPEED 10

typedef struct s_visualiser
{
	SDL_Window			*win;
	SDL_Renderer		*rend;
	TTF_Font			*font;
	char				options:3;
	int					turn;
}	t_visualiser;

typedef struct s_rgba_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_rgba_color;

/*
**	visualiser functions
*/
void		event_listner(void);
int			rgb_range(double ratio);
void		init_visualiser(t_visualiser *data);
void		draw(t_visualiser *data, t_stack a, t_stack b);
void		visualiser(t_visualiser *data, t_stack s,
				int x, int height);
void		loop_program(t_visualiser *data);
void		sdl_error(char *message);
char		is_option_activated(char option, int option_index);
int			set_options(t_visualiser *visualizator, int ac, char **av);

#endif