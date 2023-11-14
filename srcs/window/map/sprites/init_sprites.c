/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:18:16 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/14 10:10:42 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t	get_tex_count(const t_texture *const textures)
{
	size_t	count;

	count = 0;
	while (count < MAX_TEXTURE_COUNT && textures[count].data.img != NULL)
		++count;
	return (count);
}

static t_sprite	get_sprite(
	t_map *const map,
	const size_t x,
	const size_t y,
	const t_config *const config
	)
{
	const char		tile_char = map->matrix[y][x].tile_char;
	const size_t	texture_index = E_DOOR + 1
		+ index_of(SPRITES, tile_char);
	t_sprite		sprite;

	sprite.pos.x = x + SPRITE_XOFFSET;
	sprite.pos.y = y + SPRITE_YOFFSET;
	sprite.textures = config->textures[texture_index];
	sprite.tex_count = get_tex_count(sprite.textures);
	sprite.is_viewed = true;
	sprite.time = 0;
	sprite.is_crossable = (tile_char % 2);
	return (sprite);
}

static size_t	count_sprites(const t_map *const map)
{
	size_t	count;
	size_t	i;
	size_t	j;

	count = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			count += is_sprite(map, j, i);
			++j;
		}
		++i;
	}
	return (count);
}

static void	fill_sprite_array(t_map *const map, const t_config *const config)
{
	size_t	sprite_index;
	size_t	i;
	size_t	j;

	sprite_index = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (is_sprite(map, j, i))
			{
				map->sprite_array[sprite_index] = get_sprite(map, j, i, config);
				++sprite_index;
			}
			++j;
		}
		++i;
	}
}

void	init_sprites(t_map *const map, const t_config *const config)
{
	const size_t	sprite_count = count_sprites(map);

	map->sprite_count = sprite_count;
	map->sprite_array = (t_sprite *)malloc(sprite_count * sizeof(t_sprite));
	if (map->sprite_array == NULL)
	{
		print_format_error(strerror(errno));
		return ;
	}
	fill_sprite_array(map, config);
}
