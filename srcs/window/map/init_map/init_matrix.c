/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:15:46 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/07 07:14:52 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_tile(
	t_tile *tile,
	const char c,
	const size_t x,
	const size_t y
	)
{
	tile->tile_char = c;
	tile->is_marked = false;
	tile->interaction_time = 0;
	tile->state = CLOSED;
	set_pos(&(tile->pos), x, y);
}

static void	fill_with_empty_tiles(
	t_tile *const tile,
	const size_t len,
	const size_t x,
	const size_t y
	)
{
	size_t	i;

	i = x;
	while (i < len)
	{
		set_tile(tile + i, SPACE, i, y);
		++i;
	}
	set_tile(tile + i, END_CHAR, i, y);
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
			set_tile((&matrix[i][j]), lines[i][j], j, i);
			++j;
		}
		fill_with_empty_tiles(matrix[i], width, j, i);
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
