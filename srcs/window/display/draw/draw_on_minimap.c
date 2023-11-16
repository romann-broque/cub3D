/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_on_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:01:08 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/09 13:37:33 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_square_on_minimap(
	t_win *const window,
	const t_pos *const pos,
	const size_t size,
	const int color
	)
{
	const t_pos	screen_pos = find_minimap_screen_pos(window, pos);

	draw_square(window, &screen_pos, size, color);
}

void	draw_line_on_minimap(
	t_win *const window,
	const t_pos *const pos1,
	const t_pos *const pos2,
	const int color
)
{
	const t_pos	screen_pos1 = find_minimap_screen_pos(window, pos1);
	const t_pos	screen_pos2 = find_minimap_screen_pos(window, pos2);

	put_line_in_minimap(&(window->data), screen_pos1, screen_pos2, color);
}

void	draw_pos_on_minimap(
	t_win *const window,
	const t_pos *const pos,
	const int color
	)
{
	draw_coordinate_on_minimap(window, pos->x, pos->y, color);
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
	screen_pos = find_minimap_screen_pos(window, &pos);
	put_pixel(&(window->data), screen_pos.x, screen_pos.y, color);
}

void	draw_tile_on_minimap(
	t_win *const window,
	const t_pos *const pos
)
{
	const t_pos	screen_pos = find_minimap_screen_pos(window, pos);

	draw_tile(window, pos, &screen_pos);
}
