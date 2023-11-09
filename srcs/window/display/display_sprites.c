/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:21:18 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/09 14:39:42 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display_sprites_on_map(t_win *const window)
{
	const t_sprite *const	sprite_array = window->map->sprite_array;
	const size_t			sprite_count = window->map->sprite_count;
	size_t					i;

	i = 0;
	while (i < sprite_count)
	{
		draw_square_on_map(window, &(sprite_array[i].pos),
			SPRITE_SIZE, MAGENTA);
		++i;
	}
}
