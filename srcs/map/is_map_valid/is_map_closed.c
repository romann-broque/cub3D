/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_closed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:17:40 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/09 08:48:18 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_closed_dfs(
	t_map *const map,
	const ssize_t x,
	const ssize_t y
	)
{
	if (is_inside_map(map, x, y) == false)
		return (false);
	if (is_wall(map, x, y) == true || is_marked(map, x, y) == true)
		return (true);
	mark_as_viewed(map, x, y);
	return (is_closed_dfs(map, x - 1, y)
		&& is_closed_dfs(map, x + 1, y)
		&& is_closed_dfs(map, x, y - 1)
		&& is_closed_dfs(map, x, y + 1));
}

static bool	is_tile_ground(const t_tile tile)
{
	return (is_in_str(GROUND, tile.tile_char));
}

bool	is_map_closed(t_map *const map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (is_tile_ground(map->matrix[i][j]) == true)
				return (is_closed_dfs(map, j, i));
			++j;
		}
		++i;
	}
	return (true);
}
