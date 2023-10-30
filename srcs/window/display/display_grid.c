/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:50:20 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/29 11:25:15 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_tile_in_screen(const t_pos *const pos)
{
	t_pos	final_pos;

	final_pos.x = pos->x + TILE_SIZE - 1;
	final_pos.y = pos->y + TILE_SIZE - 1;
	return (is_pos_in_screen(pos) || is_pos_in_screen(&final_pos));
}

static bool	draw_map_tile(
	t_win *const window,
	const t_pos pos,
	const t_pos offset,
	t_pos pos_screen
	)
{
	const t_map *const		map = window->map;

	if (window->mod == E_STD)
	{
		set_pos(&pos_screen,
			(pos_screen.x + offset.x) * (TILE_SIZE) + MINIMAP_XOFFSET,
			(pos_screen.y + offset.y) * (TILE_SIZE) + MINIMAP_YOFFSET);
		if (is_closed_to_player(map, pos.x, pos.y) == true)
		{
			draw_tile(window, &pos, pos_screen.x, pos_screen.y);
			return (true);
		}
	}
	else if (window->mod == E_MAP)
	{
		set_pos(&pos_screen,
			(pos_screen.x - floor(map->player.pos.x))
			* (TILE_SIZE) + WINDOW_WIDTH / 2,
			(pos_screen.y - floor(map->player.pos.y))
			* (TILE_SIZE) + WINDOW_HEIGHT / 2);
		if (is_tile_in_screen(&pos_screen))
			draw_tile(window, &pos, pos_screen.x, pos_screen.y);
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
