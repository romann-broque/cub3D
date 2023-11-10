/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jess <jess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:16:12 by jess              #+#    #+#             */
/*   Updated: 2023/11/10 15:59:01 by jess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_pos	init_sprite_end(const int sprite_height, const int x)
{
	t_pos		sprite;

	sprite.y = (sprite_height / 2) + (WINDOW_HEIGHT / 2);
	if (sprite.y >= WINDOW_HEIGHT)
		sprite.y = fmin((WINDOW_HEIGHT - 1), sprite.y);
	sprite.x = (sprite_height / 2) + x;
	if (sprite.x >= WINDOW_WIDTH)
		sprite.x = fmin((WINDOW_WIDTH - 1), sprite.x);
	return (sprite);
}

t_pos	init_sprite_start(const int sprite_height, const int x)
{
	t_pos		sprite;

	sprite.y = (-sprite_height / 2) + (WINDOW_HEIGHT / 2);
	if (sprite.y < 0)
		sprite.y = fmax(0.0, sprite.y);
	sprite.x = (-sprite_height / 2) + x;
	if (sprite.x < 0)
		sprite.x = fmax(0.0, sprite.x);
	return (sprite);
}

t_pos	get_transformed_sprite_position(
	const t_sprite sprite,
	const double inv_det,
	const t_pos sprite_pos,
	const t_player player
)
{
	t_pos	new;

	new.x = inv_det *
			(player.dir.y * sprite_pos.x - player.dir.y * sprite_pos.y);
	new.y = inv_det *
			(-player.plane.y * sprite_pos.x + player.plane.x * sprite_pos.y);
	return (new);
}

t_pos	get_sprite_position_to_camera(
	const t_sprite sprite,
	const t_player player
)
{
	t_pos	new;

	new.x = sprite.pos.x - player.pos.x;
	new.y = sprite.pos.y - player.pos.y;
	return (new);
}

double	get_inv_det(const t_player player)
{
	return (1.0 / player.plane.x * player.dir.y
		- player.dir.x * player.plane.y);
}
