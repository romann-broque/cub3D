/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechon <lechon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 08:58:27 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/23 14:39:49 by lechon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vect	get_ray(const t_player player, const size_t x)
{
	const double	camera_x = 2 * (double)x / (double)WINDOW_WIDTH - 1;
	t_vect			ray;

	set_vect(&ray,
		player.dir.x + player.plane.x * (double)camera_x,
		player.dir.y + player.plane.y * (double)camera_x);
	return (ray);
}

t_vect	get_delta_dist(const t_vect ray)
{
	t_vect	delta_dist;

	set_vect(&delta_dist, 1e30, 1e30);
	if (ray.x != 0)
		delta_dist.x = fabs(1 / ray.x);
	if (ray.y != 0)
		delta_dist.y = fabs(1 / ray.y);
	return (delta_dist);
}

t_vect	get_step_from_ray(const t_vect ray)
{
	t_vect	step;

	set_vect(&step, 1, 1);
	if (ray.x < 0)
		step.x = -1;
	if (ray.y < 0)
		step.y = -1;
	return (step);
}

t_vect	get_side_dist(
	const t_pos pos,
	const t_vect ray,
	const t_vect delta_dist
	)
{
	const double	mapx = floor(pos.x);
	const double	mapy = floor(pos.y);
	t_vect			side_dist;

	if (ray.x < 0)
		side_dist.x = (pos.x - mapx) * delta_dist.x;
	else
		side_dist.x = (mapx + 1.0 - pos.x) * delta_dist.x;
	if (ray.y < 0)
		side_dist.y = (pos.y - mapy) * delta_dist.y;
	else
		side_dist.y = (mapy + 1.0 - pos.y) * delta_dist.y;
	return (side_dist);
}
