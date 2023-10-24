/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:46:36 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/24 15:37:54 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	get_perp_wall_dist(
	const t_cast cast,
	const t_vect delta_dist
	)
{
	if (cast.side == X_SIDE)
		return (cast.dist.x - delta_dist.x);
	return (cast.dist.y - delta_dist.y);
}

static void	raycast(
	t_win *const window,
	const size_t x,
	t_pos hitpoint_array[WINDOW_WIDTH]
	)
{
	const t_player	player = window->map->player;
	const t_vect	ray = get_ray(player, x);
	const t_vect	delta_dist = get_delta_dist(ray);
	const t_cast	cast = dda(window->map, player.pos, ray, delta_dist);
	const double	perp_wall_dist = get_perp_wall_dist(cast, delta_dist);

	if (window->mod == E_STD)
		draw_vertical(window, cast.side, perp_wall_dist, x);
	hitpoint_array[x] = cast.hitpoint;
}

void	raycaster(t_win *const window, t_pos hitpoint_array[WINDOW_WIDTH])
{
	size_t	x;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		raycast(window, x, hitpoint_array);
		++x;
	}
}
