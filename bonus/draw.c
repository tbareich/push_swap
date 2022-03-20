/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:32:45 by tbareich          #+#    #+#             */
/*   Updated: 2022/03/20 20:55:55 by tbareich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <visualiser.h>

static t_rgba_color	set_rgb(t_rgba_color color, int r, int g, int b)
{
	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

int	rgb_range(double ratio)
{
	int				region;
	int				x;
	t_rgba_color	color;

	region = ratio * 5;
	x = (int)(ratio * 256 * 5) % 256;
	color = (t_rgba_color){0, 0, 0, 0};
	if (region == 0)
		color = set_rgb(color, 255, x, 0);
	else if (region == 1)
		color = set_rgb(color, 255 - x, 255, 0);
	else if (region == 2)
		color = set_rgb(color, 0, 255, x);
	else if (region == 3)
		color = set_rgb(color, 0, 255 - x, 255);
	else if (region == 4)
		color = set_rgb(color, ft_convert_range(x, (t_range){0, 254},
					(t_range){0, 150}), 0, 255);
	else if (region == 5)
		color = set_rgb(color, 150, 0, 255
				- ft_convert_range(x, (t_range){0, 254}, (t_range){0, 150}));
	else
		color = set_rgb(color, 255, 255, 255);
	return (color.r | (color.g << 8) | (color.b << 16));
}

static void	write_text(t_visualiser *data, char *str, int x, int y)
{
	SDL_Color	f_color;
	SDL_Color	b_color;
	SDL_Surface	*surface_message;
	SDL_Texture	*message;
	SDL_Rect	message_rect;

	f_color = (SDL_Color){236, 240, 241, 255};
	b_color = (SDL_Color){0, 0, 0, 0};
	surface_message = TTF_RenderText_Shaded(data->font, str, f_color, b_color);
	message = SDL_CreateTextureFromSurface(data->rend, surface_message);
	message_rect.w = surface_message->w;
	message_rect.h = surface_message->h ;
	message_rect.x = x - (message_rect.w / 2);
	message_rect.y = y - (message_rect.h / 2);
	SDL_RenderCopy(data->rend, message, NULL, &message_rect);
	SDL_FreeSurface(surface_message);
	SDL_DestroyTexture(message);
}

void	draw(t_visualiser *data, t_stack a, t_stack b)
{
	if (SDL_SetRenderDrawColor(data->rend, 0, 0, 0, 255) != 0)
		sdl_error("Get color failed");
	SDL_RenderClear(data->rend);
	visualiser(data, a, 0, a.length);
	visualiser(data, b, WIN_W / 2, b.length);
	data->font = TTF_OpenFont("/Library/Fonts/Arial.ttf", 24);
	write_text(data, "Stack A", -40 + (WIN_W / 4), (WIN_H - STACK_H) / 2);
	write_text(data, "Stack B", WIN_W / 2 + (WIN_W / 4), (WIN_H - STACK_H) / 2);
	write_text(data, ft_itoa(data->turn), WIN_W - 50, WIN_H - 50);
	if (SDL_SetRenderDrawColor(data->rend, 100, 100, 100, 255) != 0)
		sdl_error("Get color failed");
	if (SDL_RenderDrawLine(data->rend, WIN_W / 2, 0, WIN_W / 2, WIN_H) != 0)
		sdl_error("Get line failed");
	if (SDL_RenderDrawLine(data->rend, 0, WIN_H - STACK_H, WIN_W,
			WIN_H - STACK_H) != 0)
		sdl_error("Get line failed");
	SDL_RenderPresent(data->rend);
	SDL_Delay(SPEED);
	event_listner();
}
