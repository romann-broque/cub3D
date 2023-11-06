/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_tiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 07:40:24 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/06 09:23:30 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	refresh_single_tile(t_tile *const tile)
{
	if (tile->tile_char == DOOR)
		refresh_door(tile);
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
			refresh_single_tile(&(map->matrix[i][j]));
			++j;
		}
		++i;
	}
}
