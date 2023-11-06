/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_open_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 06:40:48 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/06 08:42:45 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_door_as_opened(
	t_map *const map,
	const t_pos door_pos
)
{
	const size_t	x = door_pos.x;
	const size_t	y = door_pos.y;

	printf("DOOR_STATE -> %d\n", map->matrix[y][x].state);
	map->matrix[y][x].state = OPENING;
}

void	solo_raycast(
	t_win *const window,
	const size_t x
)
{
	const t_cast	cast = raycast(window, x);

	if (cast.perp_wall_dist < DOOR_RADIUS && cast.tile->tile_char == DOOR)
		set_door_as_opened(window->map, cast.tile_pos);
}

int	open_door(t_win *const ptr)
{
	if (BONUS)
		solo_raycast(ptr, WINDOW_WIDTH / 2);
	return (EXIT_SUCCESS);
}
