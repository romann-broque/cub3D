/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:08:47 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/24 20:18:40 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	draw_map_tile(
	t_win *const window,
	const t_pos pos,
	const t_pos offset,
	t_pos pos_screen
	)
{
	const t_map *const	map = window->map;

	if (window->mod == E_STD)
	{
		set_pos(&pos_screen,
			(pos_screen.x + offset.x) * (TILE_SIZE - 1) + MINIMAP_XOFFSET,
			(pos_screen.y + offset.y) * (TILE_SIZE - 1) + MINIMAP_YOFFSET);
		if (is_closed_to_player(map, pos.x, pos.y) == true)
		{
			draw_tile(window, pos, pos_screen.x, pos_screen.y);
			return (true);
		}
	}
	else if (window->mod == E_MAP)
	{
		set_pos(&pos_screen,
			(pos_screen.x + offset.x - MINIMAP_RADIUS - map->player.pos.x)
			* (TILE_SIZE - 1) + WINDOW_WIDTH / 2,
			(pos_screen.y + offset.y - MINIMAP_RADIUS - map->player.pos.y)
			* (TILE_SIZE - 1) + WINDOW_HEIGHT / 2);
		draw_tile(window, pos, pos_screen.x, pos_screen.y);
		return (true);
	}
	return (false);
}

static bool	is_tile_sequence_drawn(
	t_win *const window,
	const t_map *const map,
	const size_t y,
	const size_t i
	)
{
	const t_pos			offset = get_offset(map->player.pos);
	size_t				x;
	size_t				j;
	t_pos				pos;
	t_pos				pos_screen;

	x = 0;
	j = 0;
	while (j < map->width)
	{
		set_pos(&pos, j, i);
		set_pos(&pos_screen, x, y);
		x += draw_map_tile(window, pos, offset, pos_screen);
		++j;
	}
	return (x > 0);
}

void	display_grid(t_win *const window)
{
	const t_map *const	map = window->map;
	size_t				i;
	size_t				y;

	y = 0;
	i = 0;
	while (i < map->height)
	{
		y += is_tile_sequence_drawn(window, map, y, i);
		++i;
	}
}
