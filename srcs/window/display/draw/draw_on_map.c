/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_on_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:52:26 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/23 06:20:20 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_pos	find_screen_pos(const t_pos pos)
{
	const double	scale = TILE_SIZE - 1;
	t_pos			screen_pos;

	set_pos(&(screen_pos),
		pos.x * scale + MAP_XOFFSET, pos.y * scale + MAP_YOFFSET);
	return (screen_pos);
}

void	draw_square_on_map(
	t_win *const window,
	const t_pos pos,
	const size_t size,
	const int color
	)
{
	const t_pos	screen_pos = find_screen_pos(pos);

	draw_square(window, screen_pos, size, color);
}

void	draw_line_on_map(
	t_win *const window,
	const t_pos pos1,
	const t_pos pos2,
	const int color
)
{
	const t_pos	screen_pos1 = find_screen_pos(pos1);
	const t_pos	screen_pos2 = find_screen_pos(pos2);

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
	screen_pos = find_screen_pos(pos);
	x_screen = (int)screen_pos.x;
	y_screen = (int)screen_pos.y;
	put_pixel(&(window->data), x_screen, y_screen, color);
}
