/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:08:47 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/23 09:04:06 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_tile_sequence_drawn(
	t_win *const window,
	const size_t y,
	const size_t i
	)
{
	const t_map *const	map = window->map;
	const t_pos			offset = get_offset(map->player.pos);
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
			draw_tile(window, pos,
				(x + offset.x) * (TILE_SIZE - 1) + MINIMAP_XOFFSET,
				(y + offset.y) * (TILE_SIZE - 1) + MINIMAP_YOFFSET);
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
