/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechon <lechon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:15:46 by rbroque           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/10/23 09:54:16 by rbroque          ###   ########.fr       */
=======
/*   Updated: 2023/10/23 16:03:41 by lechon           ###   ########.fr       */
>>>>>>> MVE3
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
	set_tile(tile + i, END_CHAR, false);
}

static void	fill_matrix(
	t_tile **matrix,
	const size_t height,
	const size_t width,
	char *const *const lines)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width && lines[i][j] != END_CHAR)
		{
			set_tile((&matrix[i][j]), lines[i][j], false);
			++j;
		}
		fill_with_empty_tiles(matrix[i] + j, width - j);
		++i;
	}
}

t_tile	**init_matrix(
	const size_t height,
	const size_t width,
	char *const *const lines
	)
{
	t_tile **const	matrix = (t_tile **)malloc(height * sizeof(t_tile *));
	size_t			i;

	if (matrix == NULL)
	{
		print_format_error(strerror(errno));
		return (NULL);
	}
	i = 0;
	while (i < height)
	{
		matrix[i] = (t_tile *)malloc((width + 1) * sizeof(t_tile));
		if (matrix[i] == NULL)
		{
			print_format_error(strerror(errno));
			free_tile_matrix(matrix, height);
			return (NULL);
		}
		++i;
	}
	fill_matrix(matrix, height, width, lines);
	return (matrix);
}
