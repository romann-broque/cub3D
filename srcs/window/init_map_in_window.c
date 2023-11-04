/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_in_window.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 23:26:56 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/04 23:32:06 by rbroque          ###   ########.fr       */
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

static bool	is_texture_set(const size_t id, const t_config *const config)
{
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
		key = SPECIAL_KEYS[i];
		if (is_tile_in_matrix(key, map->matrix, map->height, map->width))
		{
			if (is_texture_set(MANDATORY_ATTRIBUTE_COUNT + i, config) == false)
			{
				print_format_error(SPECIAL_TEXTURE_NOT_SET);
				return (false);
			}
		}
		else if (is_texture_set(MANDATORY_ATTRIBUTE_COUNT + i, config) == true)
		{
			print_format_error(SPECIAL_TILE_NOT_SET);
			return (false);
		}
		++i;
	}
	return (true);
}

void	init_map_in_window(
	t_win *const window,
	const ssize_t offset,
	char *const *const file_content)
{
	window->map = init_map(file_content + offset);
	if (window->map == NULL || is_map_valid(window->map) == false
		|| is_config_matching(window->map, &(window->config)) == false)
	{
		free_map(window->map);
		window->map = NULL;
	}
}