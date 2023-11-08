/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_doors_surrounded.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:18:41 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/07 13:46:11 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_door_surrounded(
	const t_map *const map,
	const size_t x,
	const size_t y
)
{
	t_tile *const	door_tile = get_tile_from_map(map, x, y);

	if (x == 0 || x == map->width - 1
		|| y == 0 || y == map->height - 1)
		return (false);
	if (door_tile->tile_char == DOOR_HOR)
		return (is_wall(map, x, y + 1) && is_wall(map, x, y - 1));
	return (is_wall(map, x + 1, y) && is_wall(map, x - 1, y));
}

bool	are_doors_surrounded(const t_map *const map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (is_tile_door(&(map->matrix[i][j])) == true
				&& is_door_surrounded(map, j, i) == false)
				return (false);
			++j;
		}
		++i;
	}
	return (true);
}
