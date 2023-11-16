/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:50:20 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/08 09:52:48 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_tile_in_screen(const t_pos *const pos)
{
	static const size_t	offset = TILE_SIZE - 1;
	t_pos				final_pos;

	final_pos.x = pos->x + offset;
	final_pos.y = pos->y + offset;
	return (is_pos_in_screen(pos) || is_pos_in_screen(&final_pos));
}

static bool	draw_map_tile(
	t_win *const window,
	const t_pos *const pos,
	const t_pos *const pos_screen
	)
{
	if (window->mod == E_STD)
	{
		if (is_close_to_player(window->map, pos->x, pos->y))
		{
			draw_tile_on_minimap(window, pos);
			return (true);
		}
	}
	else if (window->mod == E_MAP)
	{
		if (is_tile_in_screen(pos_screen))
		{
			draw_tile_on_map(window, pos);
			return (true);
		}
	}
	return (false);
}

static bool	is_tile_sequence_drawn(
	t_win *const window,
	const t_map *const map,
	const size_t y,
	const double i
	)
{
	size_t	x;
	size_t	j;
	t_pos	pos;
	t_pos	pos_screen;

	x = 0;
	j = map->player.pos.x - floor(map->player.pos.x);
	while (j < map->width)
	{
		set_pos(&pos, j, i);
		set_pos(&pos_screen, x, y);
		x += draw_map_tile(window, &pos, &pos_screen);
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
	i = map->player.pos.y - floor(map->player.pos.y);
	while (i < map->height)
	{
		y += is_tile_sequence_drawn(window, map, y, i);
		++i;
	}
}
