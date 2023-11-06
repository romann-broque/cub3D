/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:23:18 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/06 09:27:04 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_progression(t_tile *const door)
{
	door->progression = door->interaction_time / (double)DOOR_TIME;
}

void	refresh_door(t_tile *const door)
{
	if (door->state != CLOSED)
	{
		if (door->interaction_time >= DOOR_TIME)
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
	}
	set_progression(door);
}
