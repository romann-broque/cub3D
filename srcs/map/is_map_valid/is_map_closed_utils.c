/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_closed_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 08:39:37 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/09 08:40:46 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_inside_map(
	const t_map *const map,
	const ssize_t x,
	const ssize_t y
	)
{
	return (x >= 0 && y >= 0
		&& (size_t)x < map->width && (size_t)y < map->height);
}

bool	is_wall(
	const t_map *const map,
	const size_t x,
	const size_t y
	)
{
	return (map->matrix[y][x].tile_char == WALL);
}

bool	is_marked(
	const t_map *const map,
	const size_t x,
	const size_t y
	)
{
	return (map->matrix[y][x].is_marked == true);
}

void	mark_as_viewed(
	t_map *const map,
	const size_t x,
	const size_t y
	)
{
	map->matrix[y][x].is_marked = true;
}
