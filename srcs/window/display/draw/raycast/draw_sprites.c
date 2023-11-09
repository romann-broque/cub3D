/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jess <jess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:33:58 by jess              #+#    #+#             */
/*   Updated: 2023/11/09 17:15:27 by jess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_sprite_screen(
	const double sprite_x,
	const double sprite_y,
	const double inv_det,
	const t_map *map
)
{
	const t_player	player = map->player;
	const double	transform_x = inv_det *
			(player.dir.y * sprite_x - player.dir.y * sprite_y);
	const double	transform_y = inv_det *
			(-player.plane.y * sprite_x + player.plane.x * sprite_y);
	const int		sprite_screen = int((map->sprite->texture->width / 2) *
			(1 + transform_x / transform_y));
}

static double	get_inv_det(const t_player player)
{
	return (1.0 / player.plane.x * player.dir.y
		- player.dir.x * player.plane.y);
}

static void	translate_sprite(const t_sprite sprite, const t_map *map)
{
	const t_player	player = map->player;
	const double	sprite_x = sprite.pos.x - player.pos.x;
	const double	sprite_y = sprite.pos.y - player.pos.y;
	const double	inv_det = get_inv_det(player);

	get_sprite_screen(sprite_x, sprite_y, inv_det, map);
}
 
void	display_sprite(t_win *const window)
{
	const t_sprite	*sprite = &(window->map->sprite_array);
	size_t			i;

	i = 0;
	sort_sprites(window);
	while (i < window->map->sprite_count)
	{
		if (sprite[i].is_viewed == true)
			translate_sprite(sprite[i], window->map);
		i++;
	}
}
