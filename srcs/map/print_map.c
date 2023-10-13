/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:00:52 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/12 13:09:28 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_tile(const t_tile tile)
{
	if (tile.is_marked)
		printf(GREEN"%c"NC, tile.tile_char);
	else
		printf(RED"%c"NC, tile.tile_char);
}

static void	print_matrix(
	t_tile *const*const matrix,
	const size_t height,
	const size_t width
	)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			print_tile(matrix[i][j]);
			++j;
		}
		printf("\n");
		++i;
	}
}

void	print_map(const t_map *const map)
{
	if (map != NULL)
	{
		printf("Height: %zu\nWidth: %zu\n\n", map->height, map->width);
		print_matrix(map->matrix, map->height, map->width);
	}
}
