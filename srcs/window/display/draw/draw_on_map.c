/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_on_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:52:26 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/24 22:30:33 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_pos	find_map_screen_pos(
	t_win *const window,
	const t_pos pos)
{
	const t_pos		player_pos = window->map->player.pos;
	const double	scale = TILE_SIZE;
	const double	x_screen = (pos.x - floor(player_pos.x))
		* scale + WINDOW_WIDTH / 2;
	const double	y_screen = (pos.y - floor(player_pos.y))
		* scale + WINDOW_HEIGHT / 2;
	t_pos			screen_pos;

	set_pos(&screen_pos, x_screen, y_screen);
	return (screen_pos);
}

void	draw_square_on_map(
	t_win *const window,
	const t_pos pos,
	const size_t size,
	const int color
	)
{
	const t_pos	screen_pos = find_map_screen_pos(window, pos);

	draw_square(window, screen_pos, size, color);
}

void	draw_line_on_map(
	t_win *const window,
	const t_pos pos1,
	const t_pos pos2,
	const int color
)
{
	const t_pos	screen_pos1 = find_map_screen_pos(window, pos1);
	const t_pos	screen_pos2 = find_map_screen_pos(window, pos2);

	put_line(&(window->data), screen_pos1, screen_pos2, color);
}

void	draw_pos_on_map(
	t_win *const window,
	const t_pos pos,
	const int color
	)
{
	draw_coordinate_on_map(window, pos.x, pos.y, color);
}

void	draw_coordinate_on_map(
	t_win *const window,
	const double x,
	const double y,
	const int color
	)
{
	t_pos	pos;
	t_pos	screen_pos;
	int		x_screen;
	int		y_screen;

	set_pos(&(pos), x, y);
	screen_pos = find_map_screen_pos(window, pos);
	x_screen = (int)screen_pos.x;
	y_screen = (int)screen_pos.y;
	put_pixel(&(window->data), x_screen, y_screen, color);
}
