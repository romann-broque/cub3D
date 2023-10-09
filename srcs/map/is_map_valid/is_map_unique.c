/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_unique.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:36:48 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/09 22:12:16 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_empty_line(const t_tile *const tile_line)
{
	size_t	i;

	i = 0;
	while (tile_line[i].tile_char == BLANK)
		++i;
	return (tile_line[i].tile_char == '\0');
}

static size_t	skip_empty_line(
	t_tile *const *const matrix,
	const size_t height
	)
{
	size_t	i;

	i = 0;
	while (i < height && is_empty_line(matrix[i]) == true)
		++i;
	return (i);
}

static size_t	skip_first_map(
	t_tile *const *const matrix,
	const size_t height
	)
{
	size_t	i;

	i = 0;
	while (i < height && is_empty_line(matrix[i]) == false)
		++i;
	return (i);
}

bool	is_map_unique(const t_map *const map)
{
	size_t	i;

	i = skip_empty_line(map->matrix, map->height);
	i += skip_first_map(map->matrix + i, map->height - i);
	i += skip_empty_line(map->matrix + i, map->height - i);
	return (i == map->height);
}
