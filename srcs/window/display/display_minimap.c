/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:08:47 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/18 09:27:26 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_pos	get_min_pos(const t_pos pos)
{
	t_pos	min_pos;

	min_pos.x = 0;
	if (pos.x > MINIMAP_RADIUS)
		min_pos.x = pos.x - MINIMAP_RADIUS;
	min_pos.y = 0;
	if (pos.y > MINIMAP_RADIUS)
		min_pos.y = pos.y - MINIMAP_RADIUS;
	return (min_pos);
}

static t_pos	get_max_pos(const t_pos pos)
{
	t_pos	max_pos;

	max_pos.x = SIZE_MAX;
	if (pos.x < SIZE_MAX - MINIMAP_RADIUS)
		max_pos.x = pos.x + MINIMAP_RADIUS;
	max_pos.y = SIZE_MAX;
	if (pos.y < SIZE_MAX - MINIMAP_RADIUS)
		max_pos.y = pos.y + MINIMAP_RADIUS;
	return (max_pos);
}

static bool	is_closed_to_player(
	const t_map *const map,
	const size_t x,
	const size_t y
	)
{
	const t_pos	pos = map->player_pos;
	const t_pos	min_pos = get_min_pos(pos);
	const t_pos	max_pos = get_max_pos(pos);

	return (x >= min_pos.x
		&& x <= max_pos.x
		&& y >= min_pos.y
		&& y <= max_pos.y);
}

static bool	is_tile_sequence_drawn(
	t_win *const window,
	const size_t y,
	const size_t i
	)
{
	const t_map *const	map = window->map;
	size_t				x;
	size_t				j;
	t_pos				pos;

	x = 0;
	j = 0;
	while (j < map->width)
	{
		if (is_closed_to_player(map, j, i) == true)
		{
			set_pos(&pos, j, i);
			draw_tile(window, pos, x + MINIMAP_XOFFSET, y + MINIMAP_YOFFSET);
			++x;
		}
		++j;
	}
	return (x > 0);
}

void	display_minimap(t_win *const window)
{
	const t_map *const	map = window->map;
	size_t				i;
	size_t				y;

	y = 0;
	i = 0;
	while (i < map->height)
	{
		y += is_tile_sequence_drawn(window, y, i);
		++i;
	}
}
