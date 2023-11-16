/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:00:52 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/16 14:44:43 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_tile(const t_tile tile)
{
	if (tile.is_marked)
		printf(GREEN_PRINT"%c"NC, tile.tile_char);
	else
		printf(RED_PRINT"%c"NC, tile.tile_char);
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

static void	print_sprites(
	const t_sprite *const sprite_array,
	const size_t sprite_count
	)
{
	size_t	i;

	i = 0;
	while (i < sprite_count)
	{
		printf("%zu -> %lf;%lf (%p)\n", i + 1,
			sprite_array[i].pos.x,
			sprite_array[i].pos.y,
			sprite_array[i].textures);
		++i;
	}
}

void	print_map(const t_map *const map)
{
	if (map != NULL)
	{
		printf("Height: %zu\nWidth: %zu\n\n", map->height, map->width);
		print_matrix(map->matrix, map->height, map->width);
		if (BONUS)
		{
			printf("sprites_count -> %zu\n", map->sprite_count);
			print_sprites(map->sprite_array, map->sprite_count);
		}
	}
}
