/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:05:17 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/17 15:32:01 by rbroque          ###   ########.fr       */
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

void	draw_tile(
	t_win *const window,
	const t_pos pos,
	const size_t x,
	const size_t y)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			if (is_ground(window->map, pos.x, pos.y) == true
				|| (is_wall(window->map, pos.x, pos.y) == true
					&& is_tile_side(j, i) == true))
			{
				put_pixel(&(window->data),
					x * (TILE_SIZE - 1) + j,
					y * (TILE_SIZE - 1) + i,
					get_color_from_tile(window->map, pos.x, pos.y));
			}
			++j;
		}
		++i;
	}
}
