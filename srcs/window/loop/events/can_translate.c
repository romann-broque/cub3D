/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_translate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:06:02 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/24 09:12:49 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	can_translate_forward_x(
	t_map *const map,
	const double move_speed
	)
{
	t_player *const	player = &(map->player);

	return (is_wall(
			map, player->pos.x + player->dir.x * move_speed,
			player->pos.y) == false);
}

bool	can_translate_forward_y(
	t_map *const map,
	const double move_speed
	)
{
	t_player *const	player = &(map->player);

	return (is_wall(map,
			player->pos.x,
			player->pos.y + player->dir.y * move_speed) == false);
}

bool	can_translate_side_x(
	t_map *const map,
	const double move_speed
	)
{
	t_player *const	player = &(map->player);

	return (is_wall(
			map, player->pos.x + player->dir.y * move_speed,
			player->pos.y) == false);
}

bool	can_translate_side_y(
	t_map *const map,
	const double move_speed
	)
{
	t_player *const	player = &(map->player);

	return (is_wall(map,
			player->pos.x,
			player->pos.y + player->dir.x * move_speed) == false);
}
