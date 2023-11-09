/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:07:09 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/09 13:05:00 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_going_through_door(
	t_map *const map,
	t_cast *const cast,
	const double x,
	const double y
)
{
	const t_tile *const	tile = get_tile_from_map(map, x, y);

	if (is_tile_door(tile))
	{
		if (tile->state == OPENED)
			return (true);
		if (tile->state != CLOSED)
		{
			set_hitpoint(cast, map->player.pos, x, y);
			if (tile->tile_char == DOOR_HOR)
				return (cast->hitpoint.y
					- floor(cast->hitpoint.y) >= 1 - tile->progression);
			return (cast->hitpoint.x
				- floor(cast->hitpoint.x) >= 1 - tile->progression);
		}
	}
	return (false);
}

static bool	is_transparent(
	t_map *const map,
	t_cast *const cast,
	const double x,
	const double y
	)
{
	return (is_ground(map, x, y) || is_sprite(map, x, y)
		|| is_going_through_door(map, cast, x, y));
}

static void	set_cast(
	t_map *const map,
	const t_vect delta_dist,
	t_cast *const cast
	)
{
	double	x;
	double	y;

	x = map->player.pos.x;
	y = map->player.pos.y;
	while (is_transparent(map, cast, x, y))
	{
		if (cast->dist.x < cast->dist.y)
		{
			cast->dist.x += delta_dist.x;
			x += cast->step.x;
			cast->side = WEST_FACE;
		}
		else
		{
			cast->dist.y += delta_dist.y;
			y += cast->step.y;
			cast->side = NORTH_FACE;
		}
	}
	set_side(&(cast->side), cast->step);
	cast->tile = get_tile_from_map(map, x, y);
	set_hitpoint(cast, map->player.pos, x, y);
}

static double	get_perp_wall_dist(
	const t_cast *const cast,
	const t_vect *const delta_dist
	)
{
	if (cast->side == EAST_FACE || cast->side == WEST_FACE)
		return (cast->dist.x - delta_dist->x);
	return (cast->dist.y - delta_dist->y);
}

t_cast	dda(
	t_map *const map,
	const t_pos pos,
	const t_vect ray,
	const t_vect delta_dist)
{
	const t_vect	step = get_step_from_ray(ray);
	const t_vect	side_dist = get_side_dist(pos, ray, delta_dist);
	const double	coeff = ray.y / ray.x;
	t_cast			cast;

	cast.coeff = coeff;
	cast.step = step;
	cast.dist = side_dist;
	cast.ray = ray;
	set_cast(map, delta_dist, &cast);
	cast.perp_wall_dist = get_perp_wall_dist(&cast, &delta_dist);
	return (cast);
}
