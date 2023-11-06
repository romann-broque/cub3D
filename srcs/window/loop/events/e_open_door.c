/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_open_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 06:40:48 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/06 07:12:31 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	solo_raycast(
	t_win *const window,
	const size_t x
)
{
	const t_cast	cast = raycast(window, x);

	if (cast.perp_wall_dist < DOOR_RADIUS && cast.tile == DOOR)
		printf("It's a door\n");
}

int	open_door(t_win *const ptr)
{
	if (BONUS)
		solo_raycast(ptr, WINDOW_WIDTH / 2);
	return (EXIT_SUCCESS);
}
