/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:46:36 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/06 12:57:29 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_cast	raycast(
	t_win *const window,
	const size_t x
	)
{
	const t_player	player = window->map->player;
	const t_vect	ray = get_ray(player, x);
	const t_vect	delta_dist = get_delta_dist(ray);
	const t_cast	cast = dda(window->map, player.pos, ray, delta_dist);

	return (cast);
}

void	raycaster(t_win *const window, t_pos hitpoint_array[WINDOW_WIDTH])
{
	size_t	x;
	t_cast	cast;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		cast = raycast(window, x);
		draw_vertical(window, &cast, cast.perp_wall_dist, x);
		hitpoint_array[x] = cast.hitpoint;
		++x;
	}
}
