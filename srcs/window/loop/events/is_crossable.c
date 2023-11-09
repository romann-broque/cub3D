/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_crossable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:13:41 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/09 13:18:39 by rbroque          ###   ########.fr       */
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

static bool	is_sprite_crossable(
	const t_map *const map,
	const size_t x,
	const size_t y
)
{
	return (is_sprite(map, x, y));
}

bool	is_crossable(
	const t_map *const map,
	const size_t x,
	const size_t y
	)
{
	return (is_ground(map, x, y)
		|| is_door_opened(map, x, y)
		|| is_sprite_crossable(map, x, y));
}
