/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_closed_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 08:39:37 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/17 08:55:24 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_inside_map(
	const t_map *const map,
	const ssize_t x,
	const ssize_t y
	)
{
	return (x >= 0 && y >= 0
		&& (size_t)x < map->width && (size_t)y < map->height);
}

static bool	is_marked(
	const t_map *const map,
	const size_t x,
	const size_t y
	)
{
	return (map->matrix[y][x].is_marked == true);
}

static void	mark_as_viewed(
	const t_map *const map,
	const size_t x,
	const size_t y
	)
{
	map->matrix[y][x].is_marked = true;
}

bool	is_closed_dfs(
	const t_map *const map,
	const ssize_t x,
	const ssize_t y
	)
{
	if (is_inside_map(map, x, y) == false || is_blank(map, x, y) == true)
		return (false);
	if (is_wall(map, x, y) == true || is_marked(map, x, y) == true)
		return (true);
	mark_as_viewed(map, x, y);
	return (is_closed_dfs(map, x - 1, y)
		&& is_closed_dfs(map, x + 1, y)
		&& is_closed_dfs(map, x, y - 1)
		&& is_closed_dfs(map, x, y + 1));
}
