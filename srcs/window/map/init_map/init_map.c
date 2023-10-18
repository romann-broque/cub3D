/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:43:54 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/17 15:02:17 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t	count_lines(char *const *const lines)
{
	return (get_size_strs(lines));
}

static size_t	find_max_line_length(char *const *const lines)
{
	size_t	i;
	size_t	curr_len;
	size_t	max_len;

	curr_len = 0;
	max_len = 0;
	i = 0;
	while (lines[i] != NULL)
	{
		curr_len = ft_strlen(lines[i]);
		if (curr_len > max_len)
			max_len = curr_len;
		++i;
	}
	return (max_len);
}

static t_pos	get_player_pos(t_map *const map)
{
	t_pos	pos;
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (is_player(map, x, y))
			{
				pos.x = x;
				pos.y = y;
			}
			++x;
		}
		++y;
	}
	return (pos);
}

t_map	*init_map(char *const *const lines)
{
	const size_t	height = count_lines(lines);
	const size_t	width = find_max_line_length(lines);
	t_map			*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (map == NULL)
	{
		print_format_error(strerror(errno));
		return (NULL);
	}
	map->height = height;
	map->width = width;
	map->matrix = init_matrix(height, width, lines);
	map->player_pos = get_player_pos(map);
	if (map->matrix == NULL)
		return (NULL);
	return (map);
}
