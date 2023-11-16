/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_tiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 07:40:24 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/13 15:50:31 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	refresh_single_tile(
	const t_map *const map,
	t_tile *const tile)
{
	if (is_tile_door(tile) == true)
		refresh_door(&(map->player), tile);
}

void	refresh_tiles(t_map *const map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			refresh_single_tile(map, &(map->matrix[i][j]));
			++j;
		}
		++i;
	}
}
