/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:03:07 by tbareich          #+#    #+#             */
/*   Updated: 2022/01/14 18:42:00 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <visualizator.h>


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

	if (region == 0)
	{
		r = 255;
		b = 0;
		g += x;
	}
	else if (region == 1)
	{
		r = 255;
		b = 0;
		g = 255;
	}
    switch (region)
    {
		case 0: r = 255; g = 0;   b = 0;   g += x; break;
		case 1: r = 255; g = 255; b = 0;   r -= x; break;
		case 2: r = 0;   g = 255; b = 0;   b += x; break;
		case 3: r = 0;   g = 255; b = 255; g -= x; break;
    }
    return r | (g << 8) | (b << 16);
}

void			init_visualizator(t_visualization *data)
{
	data->win = NULL;
	    //this opens a font style and sets a size
    
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
    data->font = TTF_OpenFont("/Library/Fonts/Arial.ttf", 55);
    if (data->font == NULL)
    {
        sdl_error("Font error");
    }
    SDL_PumpEvents();
}

void            write_text(t_visualization *data,char *str, int x)
{
	SDL_Color color = {236, 240, 241, 255};
	SDL_Surface* surfaceMessage =
		TTF_RenderText_Solid(data->font, str, color); 
	SDL_Texture* Message = SDL_CreateTextureFromSurface(data->rend, surfaceMessage);
	SDL_Rect Message_rect;
	Message_rect.w = 100;
	Message_rect.h = 30 ;
	Message_rect.x = x + (STACK_W / 2) - (Message_rect.w / 2);
	Message_rect.y = (WIN_H - STACK_H) / 2 - (Message_rect.h / 2);
	SDL_RenderCopy(data->rend, Message, NULL, &Message_rect);
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);
}
void            draw(t_visualization *data, t_stack a, t_stack b)
{
    if (SDL_SetRenderDrawColor(data->rend, 30, 30, 30, 255) != 0)
	    sdl_error("Get color failed");
	SDL_RenderClear(data->rend);
    visualizator(data, a, 0, a.top + b.top);
    visualizator(data, b, STACK_W, a.top + b.top);
    write_text(data, "Stack A", -40);
    write_text(data, "Stack B", STACK_W);

	if (SDL_SetRenderDrawColor(data->rend, 100, 100, 100, 255) != 0)
		sdl_error("Get color failed");
    if (SDL_RenderDrawLine(data->rend, WIN_W / 2, 0, WIN_W / 2, WIN_H) != 0)
        sdl_error("Get line failed");
    if (SDL_RenderDrawLine(data->rend, 0, WIN_H - STACK_H, WIN_W, WIN_H - STACK_H) != 0)
        sdl_error("Get line failed");
    SDL_RenderPresent(data->rend);
    event_listner();
    SDL_Delay(convert_range(a.top + b.top + 2, 0, 500, 100, 0));
    event_listner();
}

void			visualizator(t_visualization *data, t_stack s, int x, int height)
{
	int			j;
    int         color;
    int h;
    SDL_Rect rec;

	j = 0;
    if (s.top > 0)
    {
        h = STACK_H / height;
        while (j < (int)s.top)
        {
            if (is_option_activated(data->options, C_OPTION))
            {
                color = rgb((double)(s.array[j]) / height);
                if (SDL_SetRenderDrawColor(data->rend,
                            color & 0x0000FF, (color & 0x00FF00) >> 8, (color & 0xFF0000) >> 16, 255) != 0)
                  sdl_error("Get color failed");
            }
            else
                if (SDL_SetRenderDrawColor(data->rend,
                            255, 255, 255, 255) != 0)
                  sdl_error("Get color failed");
            rec.x = x;
            rec.y = ((s.top - 1 - j) * h) + (WIN_H - STACK_H);
            rec.w = (s.array[j] + 1) * (STACK_W - 40)/(height + 1);
            rec.h = h;
            if (SDL_RenderFillRect(data->rend, &rec) != 0)
                sdl_error("draw rectangle failed");
            j++;
        }
    }
}

void			loop_program(t_visualization *data)
{
	while (1)
		event_listner();
    TTF_CloseFont(data->font);
    TTF_Quit();
	SDL_DestroyRenderer(data->rend);
	SDL_DestroyWindow(data->win);
	SDL_Quit();
}