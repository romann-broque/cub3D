/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:46:36 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/19 14:55:31 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_cast	get_cast(
	t_map *const map,
	t_vect side_dist,
	const t_vect delta_dist,
	const t_vect step)
{
	size_t	x;
	size_t	y;
	t_cast	cast;

	x = (size_t)floor(map->player.pos.x);
	y = (size_t)floor(map->player.pos.y);
	cast.dist = side_dist;
	while (is_ground(map, x, y))
	{
		if (cast.dist.x < cast.dist.y)
		{
			cast.dist.x += delta_dist.x;
			x += step.x;
			cast.side = 0;
		}
		else
		{
			cast.dist.y += delta_dist.y;
			y += step.y;
			cast.side = 1;
		}
	}
	return (cast);
}

static t_cast	dda(
	t_map *const map,
	const t_pos pos,
	const t_vect ray,
	const t_vect delta_dist)
{
	const t_vect	step = get_step_from_ray(ray);
	const t_vect	side_dist = get_side_dist(pos, ray, delta_dist);

	return (get_cast(map, side_dist, delta_dist, step));
}

static void	raycast(t_win *const window, const size_t x)
{
	const t_player	player = window->map->player;
	const t_vect	ray = get_ray(player, x);
	const t_vect	delta_dist = get_delta_dist(ray);
	t_cast			cast;
	double			perp_wall_dist;

	printf("x=%zu	-> ray (%lf;%lf)\n", x, ray.x, ray.y);
	cast = dda(window->map, player.pos, ray, delta_dist);
	if (cast.side == 0)
		perp_wall_dist = cast.dist.x - delta_dist.x;
	else
		perp_wall_dist = cast.dist.y - delta_dist.y;
	printf("perpendicalar wall distance -> %lf\n", perp_wall_dist);
}

void	raycaster(t_win *const window)
{
	size_t	x;

	x = 0;
	while (x <= WINDOW_WIDTH)
	{
		raycast(window, x);
		++x;
	}
}
