/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_grid_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:03:33 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/24 22:07:24 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_pos	get_min_pos(const t_pos pos)
{
	t_pos	min_pos;

	min_pos.x = fmax(0.0, floor(pos.x - MINIMAP_RADIUS));
	min_pos.y = fmax(0.0, floor(pos.y - MINIMAP_RADIUS));
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

bool	is_closed_to_player(
	const t_map *const map,
	const size_t x,
	const size_t y
	)
{
	const t_pos	pos = map->player.pos;
	const t_pos	min_pos = get_min_pos(pos);
	const t_pos	max_pos = get_max_pos(pos);

	return (x >= min_pos.x
		&& x <= max_pos.x
		&& y >= min_pos.y
		&& y <= max_pos.y);
}

t_pos	get_offset(const t_pos player_pos)
{
	t_pos	offset;

	offset.x = floor(fmax(0.0, MINIMAP_RADIUS - player_pos.x + 1));
	offset.y = floor(fmax(0.0, MINIMAP_RADIUS - player_pos.y + 1));
	return (offset);
}
