/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:53:28 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/13 21:26:31 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	refresh_sprites(t_map *const map)
{
	t_sprite	*curr_sprite;
	size_t		i;

	i = 0;
	while (i < map->sprite_count)
	{
		curr_sprite = map->sprite_array + i;
		curr_sprite->is_viewed = false;
		if (curr_sprite->time < SPRITE_TIME * curr_sprite->tex_count)
			++curr_sprite->time;
		else
			curr_sprite->time = 0;
		++i;
	}
}
