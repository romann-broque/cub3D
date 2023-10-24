/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_move_forward.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 22:54:34 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/24 08:34:47 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	can_move_forward_x(t_map *const map, const double move_speed)
{
	t_player *const	player = &(map->player);

	return (is_wall(
			map, player->pos.x + player->dir.x * move_speed,
			player->pos.y) == false);
}

bool	can_move_forward_y(t_map *const map, const double move_speed)
{
	t_player *const	player = &(map->player);

	return (is_wall(map,
			player->pos.x,
			player->pos.y + player->dir.y * move_speed) == false);
}

void	translate_player_x(t_player *const player, const double move_speed)
{
	player->pos.x += player->dir.x * move_speed;
}

void	translate_player_y(t_player *const player, const double move_speed)
{
	player->pos.y += player->dir.y * move_speed;
}

int	move_forward(t_win *const ptr)
{
	t_map *const	map = ptr->map;
	const double	move_speed = 0.05;

	if (can_move_forward_x(map, move_speed) == true)
		translate_player_x(&(map->player), move_speed);
	if (can_move_forward_y(map, move_speed) == true)
		translate_player_y(&(map->player), move_speed);
	printf("Current player position -> (%lf;%lf)\n",
		map->player.pos.x, map->player.pos.y);
	return (EXIT_SUCCESS);
}
