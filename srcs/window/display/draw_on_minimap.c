/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_on_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:01:08 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/19 21:51:54 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_pos	find_screen_pos(
	t_win *const window,
	const t_pos pos)
{
	const t_pos		player_pos = window->map->player.pos;
	const double	scale = TILE_SIZE - 1;
	const double	x_screen = (fabs(pos.x - floor(player_pos.x))
			+ MINIMAP_RADIUS) * scale + MINIMAP_XOFFSET;
	const double	y_screen = (fabs(pos.y - floor(player_pos.y))
			+ MINIMAP_RADIUS) * scale + MINIMAP_YOFFSET;
	t_pos			screen_pos;

	set_pos(&screen_pos, x_screen, y_screen);
	return (screen_pos);
}

void	draw_square_on_minimap(
	t_win *const window,
	const t_pos pos,
	const size_t size,
	const int color
	)
{
	const t_pos	screen_pos = find_screen_pos(window, pos);
	const int	x_screen = (int)screen_pos.x;
	const int	y_screen = (int)screen_pos.y;
	size_t		i;
	size_t		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			put_pixel(&(window->data), x_screen + j, y_screen + i, color);
			put_pixel(&(window->data), x_screen - j, y_screen + i, color);
			put_pixel(&(window->data), x_screen + j, y_screen - i, color);
			put_pixel(&(window->data), x_screen - j, y_screen - i, color);
			++j;
		}
		++i;
	}
}

void	draw_pos_on_minimap(
	t_win *const window,
	const t_pos pos,
	const int color
	)
{
	draw_coordinate_on_minimap(window, pos.x, pos.y, color);
}

void	draw_coordinate_on_minimap(
	t_win *const window,
	const double x,
	const double y,
	const int color
	)
{
	t_pos	pos;
	t_pos	screen_pos;

	set_pos(&pos, x, y);
	screen_pos = find_screen_pos(window, pos);
	put_pixel(&(window->data), screen_pos.x, screen_pos.y, color);
}
