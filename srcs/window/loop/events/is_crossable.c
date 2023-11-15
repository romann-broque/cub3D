/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_crossable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:13:41 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/15 21:53:39 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_door_opened(
	const t_map *const map,
	const size_t x,
	const size_t y
)
{
	const t_tile *const	tile = get_tile_from_map(map, x, y);

	return (is_tile_door(tile) && tile->state == OPENED);
}

static bool	is_crossable_block(
	const t_map *const map,
	const double x,
	const double y
)
{
	return (is_ground(map, x, y)
		|| is_door_opened(map, x, y)
		|| (BONUS == true && is_sprite_crossable(map, x, y)));
}

bool	is_crossable(
	const t_map *const map,
	const double x,
	const double y
	)
{
	return (is_crossable_block(map, x, y + COLLISION_DIST)
		&& is_crossable_block(map, x + COLLISION_DIST, y)
		&& is_crossable_block(map, x, y - COLLISION_DIST)
		&& is_crossable_block(map, x - COLLISION_DIST, y));
}
