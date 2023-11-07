/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:23:18 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/07 07:19:00 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_progression(t_tile *const door)
{
	if (door->state == OPENING)
		door->progression = door->interaction_time / (double)DOOR_TIME;
	else if (door->state == CLOSING)
		door->progression = 1 - door->interaction_time / (double)DOOR_TIME;
}

bool	is_tile_door(const t_tile *const tile)
{
	return (tile->tile_char == DOOR_HOR
		|| tile->tile_char == DOOR_VERT);
}

static bool	is_player_away(
	const t_player *const player,
	t_tile *const door
)
{
	return (floor(player->pos.x - door->pos.x) != 0
		|| floor(player->pos.y - door->pos.y) != 0);
}

void	refresh_door(
	const t_player *const player,
	t_tile *const door)
{
	if (door->state != CLOSED)
	{
		if (door->interaction_time >= DOOR_TIME
			&& is_player_away(player, door))
		{
			door->interaction_time = 0;
			if (door->state == OPENING)
				door->state = OPENED;
			else if (door->state == OPENED)
				door->state = CLOSING;
			else if (door->state == CLOSING)
				door->state = CLOSED;
		}
		else
			++door->interaction_time;
		set_progression(door);
	}
}