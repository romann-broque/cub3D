/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:33:58 by jess              #+#    #+#             */
/*   Updated: 2023/11/13 15:50:31 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_pos	transform_sprite(
	t_sprite *const sprite,
	const t_player *const player
	)
{
	const double	inv_det = get_inv_det(player);
	const t_pos		sprite_pos = get_sprite_position_to_camera(sprite, player);
	const t_pos		transform = get_transformed_sprite_position(
			inv_det, sprite_pos, player);

	return (transform);
}

void	display_sprites(t_win *const window)
{
	t_sprite *const	sprites = window->map->sprite_array;
	t_pos			transform;
	size_t			i;

	i = 0;
	sort_sprites(window);
	while (i < window->map->sprite_count)
	{
		if (sprites[i].is_viewed == true)
		{
			transform = transform_sprite(sprites + i, &(window->map->player));
			draw_sprite(&(window->data), sprites + i, transform);
		}
		i++;
	}
}
