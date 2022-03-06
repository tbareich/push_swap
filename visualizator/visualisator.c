/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:03:07 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/05 19:40:30 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <visualisator.h>


char        is_option_activated(char option, int option_index)
{
    return ((option >> option_index) & 1);
}

void			sdl_error(char *message)
{
	SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
	SDL_Quit();
	exit(-1);
}

int convert_range(int n, int old_min, int old_max, int new_min, int new_max)
{
    return ((((n - old_min) * (new_max - new_min)) /
					(old_max - old_min)) + new_min);
}

void    event_listner()
{
    SDL_Event	event;

    if (SDL_PollEvent(&event))
    {
        if ((event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
                    || event.type == SDL_QUIT)
            exit(0);
    }
}

uint32_t rgb(double ratio)
{
    int normalized = (int)(ratio * 256 * 4);
    int region = normalized / 256;
    int x = normalized % 256;

    uint8_t r = 0, g = 0, b = 0;

    switch (region)
    {
		case 0: r = 255; g = 0;   b = 0;   g += x; break;
		case 1: r = 255; g = 255; b = 0;   r -= x; break;
		case 2: r = 0;   g = 255; b = 0;   b += x; break;
		case 3: r = 0;   g = 255; b = 255; g -= x; break;
    }
    return r | (g << 8) | (b << 16);
}

void			init_visualisator(t_visualizator *data)
{
	data->win = NULL;
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		sdl_error("initialisation SDL");
	if (!(data->win = SDL_CreateWindow("PUSH SWAP :)", SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED, WIN_W, WIN_H, SDL_WINDOW_SHOWN)))
		sdl_error("Creation window");
	if (!(data->rend = SDL_CreateRenderer(data->win, -1,
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
		sdl_error("Creation render");
	if (SDL_SetRenderDrawColor(data->rend, 0, 0, 0, 255) != 0)
		sdl_error("Get color failed");
     if( TTF_Init() != 0)
         sdl_error("Font init error");
    data->font = TTF_OpenFont("/Library/Fonts/Arial.ttf", 24);
    if (data->font == NULL)
    {
        sdl_error("Font error");
    }
    SDL_PumpEvents();
}

static void		write_text(t_visualizator *data, char *str, int x, int y)
{
	SDL_Color fcolor = {236, 240, 241, 255};
	SDL_Color bcolor = { 0, 0, 0, 0};
	SDL_Surface* surfaceMessage =
		TTF_RenderText_Shaded(data->font, str, fcolor, bcolor); 
	SDL_Texture* Message = SDL_CreateTextureFromSurface(data->rend, surfaceMessage);
	SDL_Rect Message_rect;
	Message_rect.w = surfaceMessage->w;
	Message_rect.h = surfaceMessage->h ;
	Message_rect.x = x - (Message_rect.w / 2);
	Message_rect.y = y - (Message_rect.h / 2);
	SDL_RenderCopy(data->rend, Message, NULL, &Message_rect);
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);
}
void            draw(t_visualizator *data, t_stack a, t_stack b)
{
    if (SDL_SetRenderDrawColor(data->rend, 0, 0, 0, 255) != 0)
	    sdl_error("Get color failed");
	SDL_RenderClear(data->rend);
    visualizator(data, a, 0, a.length);
    visualizator(data, b, WIN_W / 2, b.length);
	data->font = TTF_OpenFont("/Library/Fonts/Arial.ttf", 24);
    write_text(data, "Stack A", -40 + (WIN_W / 4), (WIN_H - STACK_H) / 2);
    write_text(data, "Stack B", WIN_W / 2 + (WIN_W / 4), (WIN_H - STACK_H) / 2);
    write_text(data, ft_itoa(data->turn),  WIN_W - 50 , WIN_H - 50);
	if (SDL_SetRenderDrawColor(data->rend, 100, 100, 100, 255) != 0)
		sdl_error("Get color failed");
    if (SDL_RenderDrawLine(data->rend, WIN_W / 2, 0, WIN_W / 2, WIN_H) != 0)
        sdl_error("Get line failed");
    if (SDL_RenderDrawLine(data->rend, 0, WIN_H - STACK_H, WIN_W, WIN_H - STACK_H) != 0)
        sdl_error("Get line failed");
    SDL_RenderPresent(data->rend);
    event_listner();
    // SDL_Delay(1000);
    // SDL_Delay(convert_range(a.length, 0, 500, 100, 0));
    event_listner();
}

void			visualizator(t_visualizator *data, t_stack s, int x, int height)
{
	int			i;
    int         color;
    int h;
    SDL_Rect rec;

	i = 0;
	h = STACK_H / height;
	if (SDL_SetRenderDrawColor(data->rend,
				10, 10, 10, 255) != 0)
		sdl_error("Get color failed");
	rec.w = STACK_W;
	rec.x = x + WIN_W / 4 - rec.w / 2;
	rec.y = WIN_H - STACK_H;
	rec.h = STACK_H;
		if (SDL_RenderFillRect(data->rend, &rec) != 0)
			sdl_error("draw rectangle failed");
    if (s.top > 0)
    {
        while (i < s.top)
        {
            if (is_option_activated(data->options, C_OPTION))
            {
                color = rgb((double)(s.length - 1 - s.array[i].value) / height);
                if (SDL_SetRenderDrawColor(data->rend,
                            color & 0x0000FF, (color & 0x00FF00) >> 8, (color & 0xFF0000) >> 16, 255) != 0)
                  sdl_error("Get color failed");
            }
            else
                if (SDL_SetRenderDrawColor(data->rend,
                           255, 215, 0, 255) != 0)
                  sdl_error("Get color failed");
            rec.w = convert_range(s.array[i].value, 0, height,  (STACK_W / height) * (height / 3), STACK_W);
            rec.h = h;
            rec.x = x + WIN_W / 4 - rec.w / 2;
            rec.y = (s.top - i - 1) * h + (WIN_H - STACK_H);
            if (SDL_RenderFillRect(data->rend, &rec) != 0)
                sdl_error("draw rectangle failed");
			++i;
        }
    }
}

void			loop_program(t_visualizator *data)
{
	while (1)
		event_listner();
    TTF_CloseFont(data->font);
    TTF_Quit();
	SDL_DestroyRenderer(data->rend);
	SDL_DestroyWindow(data->win);
	SDL_Quit();
}