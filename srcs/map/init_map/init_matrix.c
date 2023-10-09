/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:15:46 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/09 08:49:19 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_tile(t_tile *tile, const char c, const bool is_marked)
{
	tile->tile_char = c;
	tile->is_marked = is_marked;
}

static void	fill_with_empty_tiles(t_tile *tile, const size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		set_tile(tile + i, SPACE, false);
		tile[i].tile_char = SPACE;
		++i;
	}
	set_tile(tile + i, '\0', false);
}

static void	fill_matrix(
	t_tile **matrix,
	const size_t height,
	const size_t width,
	const char *const lines)
{
	size_t	i;
	size_t	j;
	size_t	offset;

	offset = 0;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width
			&& lines[offset + j] != '\0' && lines[offset + j] != '\n')
		{
			set_tile((&matrix[i][j]), lines[offset + j], false);
			++j;
		}
		fill_with_empty_tiles(matrix[i] + j, width - j);
		offset += j + (lines[offset + j] == '\n');
		++i;
	}
}

t_tile	**init_matrix(
	const size_t height,
	const size_t width,
	const char *const lines
	)
{
	t_tile **const	matrix = (t_tile **)malloc(height * sizeof(t_tile *));
	size_t			i;

	if (matrix == NULL)
		return (NULL);
	i = 0;
	while (i < height)
	{
		matrix[i] = (t_tile *)malloc((width + 1) * sizeof(t_tile));
		if (matrix[i] == NULL)
		{
			free_tile_matrix(matrix, height);
			return (NULL);
		}
		++i;
	}
	fill_matrix(matrix, height, width, lines);
	return (matrix);
}