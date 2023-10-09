/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_closed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:17:40 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/09 07:46:54 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_inside_map(
	const ssize_t x,
	const ssize_t y,
	const t_map *const map
	)
{
	return (x > 0 && y > 0
		&& (size_t)x < map->width && (size_t)y < map->height);
}

static bool	is_wall(
	const t_map *const map,
	const size_t x,
	const size_t y
	)
{
	return (map->matrix[y][x] == '1');
}

static void	mark_as_viewed(
	t_map *const map,
	const size_t x,
	const size_t y
	)
{
	map->matrix[y][x] = '1';
}

static bool	is_closed_dfs(
	t_map *const map,
	const ssize_t x,
	const ssize_t y
	)
{
	if (is_inside_map(x, y, map) == false)
		return (false);
	if (is_wall(map, x, y) == true)
		return (true);
	mark_as_viewed(map, x, y);
	return (is_closed_dfs(map, x - 1, y)
		&& is_closed_dfs(map, x + 1, y)
		&& is_closed_dfs(map, x, y - 1)
		&& is_closed_dfs(map, x, y + 1));
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
			if (map->matrix[i][j] == '0')
				return (is_closed_dfs(map, j, i));
			++j;
		}
		++i;
	}
	return (true);
}
