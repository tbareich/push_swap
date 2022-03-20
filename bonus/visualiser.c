/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualiser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:03:07 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/20 21:52:22 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <visualiser.h>

void	sdl_error(char *message)
{
	SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
	SDL_Quit();
	exit(-1);
}

void	event_listner(void)
{
	SDL_Event	event;

	if (SDL_PollEvent(&event))
	{
		if ((event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
			|| event.type == SDL_QUIT)
			exit(0);
	}
}

void	init_visualiser(t_visualiser *data)
{
	data->win = NULL;
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		sdl_error("initialisation SDL");
	data->win = SDL_CreateWindow("PUSH SWAP :)", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, WIN_W, WIN_H, SDL_WINDOW_SHOWN);
	if (!data->win)
		sdl_error("Creation window");
	data->rend = SDL_CreateRenderer(data->win, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!data->rend)
		sdl_error("Creation render");
	if (SDL_SetRenderDrawColor(data->rend, 100, 100, 100, 255) != 0)
		sdl_error("Get color failed");
	if (TTF_Init() != 0)
		sdl_error("Font init error");
	data->font = TTF_OpenFont("/Library/Fonts/Arial.ttf", 24);
	if (data->font == NULL)
		sdl_error("Font error");
	SDL_PumpEvents();
}

void	visualiser(t_visualiser *data, t_stack s, int x, int height)
{
	int			i;
	int			color;
	SDL_Rect	rect;
	int			h;

	i = -1;
	h = STACK_H / height;
	while (++i < s.top)
	{
		if (is_option_activated(data->options, C_OPTION))
		{
			color = rgb_range((double)(height - s.array[i].value) / height);
			if (SDL_SetRenderDrawColor(data->rend, color & 0x0000FF, (color
						& 0x00FF00) >> 8, (color & 0xFF0000) >> 16, 255) != 0)
				sdl_error("Get color failed");
		}
		else if (SDL_SetRenderDrawColor(data->rend, 255, 215, 0, 255) != 0)
			sdl_error("Get color failed");
		rect.w = ft_convert_range(s.array[i].value, (t_range){0, height},
				(t_range){(STACK_W / height) + 1, STACK_W});
		rect = (SDL_Rect){x + WIN_W / 4 - rect.w / 2, (s.top - i - 1) * h
			+ (WIN_H - STACK_H), rect.w, h};
		if (SDL_RenderFillRect(data->rend, &rect) != 0)
			sdl_error("draw rectangle failed");
	}
}

void	loop_program(t_visualiser *data)
{
	while (1)
		event_listner();
	TTF_CloseFont(data->font);
	TTF_Quit();
	SDL_DestroyRenderer(data->rend);
	SDL_DestroyWindow(data->win);
	SDL_Quit();
}
