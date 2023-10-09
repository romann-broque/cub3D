/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:43:54 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/09 21:59:02 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t	count_lines(const char *const lines)
{
	const size_t	total_len = ft_strlen(lines);
	size_t			count;

	count = count_c_in_str(lines, NEWLINE);
	if (total_len > 0)
		count += (lines[total_len - 1] != '\n');
	return (count);
}

static size_t	find_max_line_length(const char *map)
{
	size_t	curr_len;
	size_t	max_len;
	size_t	i;

	i = 0;
	curr_len = 0;
	max_len = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
			curr_len = 0;
		else
			++curr_len;
		if (curr_len > max_len)
			max_len = curr_len;
		++i;
	}
	return (max_len);
}

t_map	*init_map(const char *const lines)
{
	const size_t	height = count_lines(lines);
	const size_t	width = find_max_line_length(lines);
	t_map			*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map->height = height;
	map->width = width;
	map->matrix = init_matrix(height, width, lines);
	return (map);
}
