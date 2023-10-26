/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:07:09 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/26 12:28:22 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_hitpoint(
	t_cast *const cast,
	const t_pos player_pos,
	const size_t x,
	const size_t y
	)
{
	if (cast->side == WEST_FACE || cast->side == EAST_FACE)
	{
		cast->hitpoint.x = x + (cast->step.x == -1);
		cast->hitpoint.y = cast->coeff * (cast->hitpoint.x - player_pos.x)
			+ player_pos.y;
	}
	else
	{
		cast->hitpoint.y = y + (cast->step.y == -1);
		cast->hitpoint.x = (cast->hitpoint.y - player_pos.y) / cast->coeff
			+ player_pos.x;
	}
}

static void	set_cast(
	t_map *const map,
	const t_vect delta_dist,
	t_cast *const cast
	)
{
	size_t	x;
	size_t	y;

	x = map->player.pos.x;
	y = map->player.pos.y;
	while (is_ground(map, x, y))
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
	if (cast->side == WEST_FACE && cast->step.x < 0)
		cast->side = EAST_FACE;
	else if (cast->side == NORTH_FACE && cast->step.y < 0)
		cast->side = SOUTH_FACE;
	set_hitpoint(cast, map->player.pos, x, y);
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
	return (cast);
}
