/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:45:13 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/14 10:30:10 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_sprite_as_viewed(
	t_map *const map,
	const double x,
	const double y
	)
{
	t_sprite	*sprite;
	size_t		i;

	i = 0;
	while (i < map->sprite_count)
	{
		sprite = map->sprite_array + i;
		if (is_on_tile(&(sprite->pos), x, y))
			sprite->is_viewed = true;
		++i;
	}
}

bool	is_sprite_crossable(
	const t_map *const map,
	const double x,
	const double y
	)
{
	t_sprite	*sprite;
	size_t		i;

	i = 0;
	while (i < map->sprite_count)
	{
		sprite = map->sprite_array + i;
		if (is_on_tile(&(sprite->pos), x, y))
			return (sprite->is_crossable);
		++i;
	}
	return (false);
}

bool	is_sprite(const t_map *const map, const size_t x, const size_t y)
{
	return (is_in_str(SPRITES, map->matrix[y][x].tile_char));
}
