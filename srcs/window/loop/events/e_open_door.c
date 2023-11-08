/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_open_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 06:40:48 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/07 07:48:09 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_door_as_opened(
	t_tile *const door
)
{
	if (door->state == CLOSED)
		door->state = OPENING;
}

void	solo_raycast(
	t_win *const window,
	const size_t x
)
{
	const t_cast	cast = raycast(window, x);

	if (cast.perp_wall_dist < DOOR_RADIUS && is_tile_door(cast.tile) == true)
		set_door_as_opened(cast.tile);
}

int	open_door(t_win *const ptr)
{
	if (BONUS)
		solo_raycast(ptr, WINDOW_WIDTH / 2);
	return (EXIT_SUCCESS);
}
