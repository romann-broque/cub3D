/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:37:04 by jess              #+#    #+#             */
/*   Updated: 2023/11/16 12:20:14 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	swap_sprites(t_win *const window)
{
	size_t		i;
	size_t		j;
	t_sprite	tmp;
	t_sprite	*sprites;

	i = 0;
	sprites = window->map->sprite_array;
	while (i < window->map->sprite_count)
	{
		j = i + 1;
		while (j < window->map->sprite_count)
		{
			if (sprites[i].sq_distance < sprites[j].sq_distance)
			{
				tmp = sprites[i];
				sprites[i] = sprites[j];
				sprites[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	set_sprite_distance(t_win *const window)
{
	const t_player	player = window->map->player;
	t_sprite		*sprites;
	size_t			i;

	i = 0;
	sprites = window->map->sprite_array;
	while (i < window->map->sprite_count)
	{
		sprites[i].sq_distance = 0;
		if (sprites[i].is_viewed == true)
		{
			sprites[i].sq_distance
				= square_dist(&player.pos, &(sprites[i].pos));
		}
		i++;
	}
}

void	sort_sprites(t_win *const window)
{
	set_sprite_distance(window);
	swap_sprites(window);
}
