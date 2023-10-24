/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:03:14 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/24 09:05:52 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	translate_player_backfront_x(
	t_player *const player,
	const double move_speed
	)
{
	player->pos.x += player->dir.x * move_speed;
}

void	translate_player_backfront_y(
	t_player *const player,
	const double move_speed
	)
{
	player->pos.y += player->dir.y * move_speed;
}

void	translate_player_side_x(
	t_player *const player,
	const double move_speed
	)
{
	player->pos.x += player->dir.y * move_speed;
}

void	translate_player_side_y(
	t_player *const player,
	const double move_speed
	)
{
	player->pos.y += player->dir.x * move_speed;
}
