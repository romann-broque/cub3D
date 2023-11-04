/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 22:24:23 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/30 22:24:40 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	translate_side(
	t_map *const map,
	t_player *const player,
	const double move_speed
)
{
	t_vect	side_dir;

	set_vect(&side_dir, player->dir.y, -player->dir.x);
	player->pos = get_translated_pos(map, player->pos, side_dir, move_speed);
}

void	translate_frontback(
	t_map *const map,
	t_player *const player,
	const double move_speed
)
{
	player->pos = get_translated_pos(map, player->pos, player->dir, move_speed);
}
