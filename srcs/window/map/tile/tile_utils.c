/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tile_from_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:33:23 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/13 15:44:36 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_on_tile(
	const t_pos *const pos,
	const size_t x,
	const size_t y
	)
{
	return (floor(pos->x) == x && floor(pos->y) == y);
}

t_tile	*get_tile_from_map(
	const t_map *const map,
	const size_t x,
	const size_t y
)
{
	return (&(map->matrix[y][x]));
}
