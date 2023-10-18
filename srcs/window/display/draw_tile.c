/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:05:17 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/18 07:28:07 by rbroque          ###   ########.fr       */
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

static uint32_t	get_color_from_tile(
	const t_map *const map,
	const size_t x,
	const size_t y
	)
{
	if (is_player(map, x, y))
		return (BLUE);
	if (is_wall(map, x, y) || is_ground(map, x, y))
		return (WHITE);
	return (BLACK);
}

static void	draw_tile_width(
	t_win *const window,
	const t_pos tile_pos,
	const t_pos screen_pos,
	const size_t line_index
	)
{
	size_t		j;

	j = 0;
	while (j < TILE_SIZE)
	{
		if (is_ground(window->map, tile_pos.x, tile_pos.y) == true
			|| (is_wall(window->map, tile_pos.x, tile_pos.y) == true
				&& is_tile_side(j, line_index) == true))
		{
			put_pixel(&(window->data),
				screen_pos.x * (TILE_SIZE - 1) + j,
				screen_pos.y * (TILE_SIZE - 1) + line_index,
				get_color_from_tile(window->map, tile_pos.x, tile_pos.y));
		}
		++j;
	}
}

void	draw_tile(
	t_win *const window,
	const t_pos pos,
	const size_t x,
	const size_t y)
{
	const int	tile_posx = pos.x;
	const int	tile_posy = pos.y;
	t_pos		tile_pos;
	t_pos		screen_pos;
	size_t		i;

	set_pos(&tile_pos, tile_posx, tile_posy);
	set_pos(&screen_pos, (int)x, (int)y);
	i = 0;
	while (i < TILE_SIZE)
	{
		draw_tile_width(window, tile_pos, screen_pos, i);
		++i;
	}
}