/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizator.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:02:18 by tbareich          #+#    #+#             */
/*   Updated: 2022/01/14 13:14:37 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZATOR_H
# define VISUALIZATOR_H

# include <libft.h>
# include <SDL2/SDL.h>
# include <SDL2/SDL_ttf.h>

# define WIN_W 1500
# define WIN_H 1100
# define STACK_H 1000
# define STACK_W 750
# define V_OPTION 0
# define C_OPTION 1

typedef struct		s_visualization
{
	SDL_Window			*win;
	SDL_Renderer		*rend;
    char              options:2;
    TTF_Font            *font;
}					t_visualization;

void		event_listner();
uint32_t	rgb(double ratio);
void		init_visualizator(t_visualization *data);
void		write_text(t_visualization *data,char *str, int x);
void		draw(t_visualization *data, t_stack a, t_stack b);
void		visualizator(t_visualization *data, t_stack s,
						int x, int height);
void		loop_program(t_visualization *data);
char		is_option_activated(char option, int option_index);
#endif