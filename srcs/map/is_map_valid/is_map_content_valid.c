/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_content_valid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:33:53 by jrouillo          #+#    #+#             */
/*   Updated: 2023/10/09 16:55:23 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_unique_direction(const t_map *const map)
{
	size_t	count;
	size_t	i;
	size_t	j;

	count = 0;
	i = 0;
	j = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			count += count_c_in_str(&map->matrix[i][j].tile_char,
					VALID_CHAR_DIR[i]);
			j++;
		}
		i++;
	}
	if (count == 1)
		return (true);
	return (false);
}

static bool	is_charset_valid(const t_map *const map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (is_in_str(VALID_CHAR, map->matrix[i][j].tile_char) == false)
				return (false);
			j++;
		}		
		i++;
	}
	return (true);
}

bool	is_map_content_valid(const t_map *const map)
{
	return (is_charset_valid(map) && is_unique_direction(map));
}
