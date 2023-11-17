/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:05:17 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/17 11:23:32 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_tile_side(
	const size_t j,
	const size_t i
	)
{
	return (j == 0 || j == TILE_SIZE - 1 || i == 0 || i == TILE_SIZE - 1);
}

static uint32_t	get_color_from_door_pos(
	const t_map *const map,
	const t_pos tile_pos,
	const size_t x_pos,
	const size_t y_pos
)
{
	static const double	middle = TILE_SIZE / 2;
	const size_t		x = tile_pos.x;
	const size_t		y = tile_pos.y;
	const char			door = map->matrix[y][x].tile_char;

	if ((door == DOOR_HOR && fabs(x_pos - middle) < DOOR_WIDTH)
		|| (door == DOOR_VERT && fabs(y_pos - middle) < DOOR_WIDTH))
		return (GREEN);
	return (WHITE);
}

static uint32_t	get_color_from_tile(
	const t_win *const window,
	const t_pos tile_pos,
	const size_t x_pos,
	const size_t y_pos
	)
{
	const t_map *const	map = window->map;

	if (is_wall(map, tile_pos.x, tile_pos.y)
		&& is_tile_side(x_pos, y_pos) == false)
		return (BLACK);
	else if (is_door(map, tile_pos.x, tile_pos.y))
		return (get_color_from_door_pos(map, tile_pos, x_pos, y_pos));
	return (WHITE);
}

static void	draw_tile_width(
	t_win *const window,
	const t_pos *const tile_pos,
	const t_pos *const screen_pos,
	const double line_index
	)
{
	int		color;
	double	j;

	j = 0;
	while (j < TILE_SIZE)
	{
		if (is_blank(window->map, tile_pos->x, tile_pos->y) == false)
		{
			color = get_color_from_tile(
					window, *tile_pos, j, line_index);
			put_tile_pixel(window,
				screen_pos->x + j,
				screen_pos->y + line_index,
				color);
		}
		++j;
	}
}

void	draw_tile(
	t_win *const window,
	const t_pos *const pos,
	const t_pos *const screen_pos)
{
	t_pos	tile_pos;
	double	i;

	set_pos(&tile_pos, pos->x, pos->y);
	i = 0;
	while (i < TILE_SIZE)
	{
		draw_tile_width(window, &tile_pos, screen_pos, i);
		++i;
	}
}
