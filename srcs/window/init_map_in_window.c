/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_in_window.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 23:26:56 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/09 08:49:10 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_tile_in_matrix(
	const char tile,
	t_tile **matrix,
	const size_t height,
	const size_t width)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width - 1)
		{
			if (matrix[i][j].tile_char == tile)
				return (true);
			++j;
		}
		++i;
	}
	return (false);
}

static bool	is_texture_set(size_t id, const t_config *const config)
{
	if (id == E_DOOR + 1)
		id = E_DOOR;
	else if (id > E_DOOR + 1)
		--id;
	return (config->attribute_array[id] != NULL);
}

static bool	is_config_matching(
	const t_map *const map,
	const t_config *const config
	)
{
	size_t	i;
	char	key;

	i = 0;
	while (i < SPECIAL_TILE_COUNT)
	{
		key = SPECIAL_TILES[i];
		if (is_tile_in_matrix(key, map->matrix, map->height, map->width))
		{
			if (is_texture_set(MANDATORY_ATTRIBUTE_COUNT + i, config) == false)
			{
				print_format_error(SPECIAL_TEXTURE_NOT_SET);
				return (false);
			}
		}
		++i;
	}
	return (true);
}

static bool	can_map_be_used(
	t_map *const map,
	const t_config *const config
)
{
	return (map != NULL
		&& is_map_valid(map) == true
		&& (BONUS == false
			|| is_config_matching(map, config) == true));
}

void	init_map_in_window(
	t_win *const window,
	const ssize_t offset,
	char *const *const file_content)
{
	window->map = init_map(file_content + offset);
	if (can_map_be_used(window->map, &(window->config)) == false)
	{
		free_map(window->map);
		window->map = NULL;
	}
}
