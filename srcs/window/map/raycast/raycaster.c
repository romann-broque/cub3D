/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:46:36 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/20 13:18:23 by rbroque          ###   ########.fr       */
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

static t_pos	find_hit_pos(
	const t_player player,
	const t_vect ray,
	const t_vect cast_dist
)
{
	const double	x_ray = (double)ray.x * cast_dist.x;
	const double	y_ray = (double)ray.y * cast_dist.y;
	double			x;
	double			y;
	t_pos			hit_pos;

	x = player.pos.x;
	if (fabs(x_ray) < MAX_LEN_RAY)
		x = player.pos.x + x_ray;
	y = player.pos.y;
	if (fabs(y_ray) < MAX_LEN_RAY)
		y = player.pos.y + y_ray;
	printf("ray.x -> %lf\n", ray.x);
	printf("ray.y -> %lf\n", ray.y);
	printf("cast.x -> %lf\n", cast_dist.x);
	printf("cast.y -> %lf\n", cast_dist.y);
	printf("x_ray -> %lf\n", x_ray);
	printf("y_ray -> %lf\n", y_ray);
	set_pos(&(hit_pos), x, y);
	return (hit_pos);
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
	{
		cast.dist.x -= delta_dist.x;
		perp_wall_dist = cast.dist.x;
	}
	else
	{
		cast.dist.y -= delta_dist.y;
		perp_wall_dist = cast.dist.y;
	}
	printf("x=%zu	-> cast (%lf;%lf)\n", x, cast.dist.x, cast.dist.y);
	printf("perpendicular wall distance -> %lf\n", perp_wall_dist);
}

	// t_pos	hit_pos = find_hit_pos(player, ray, cast.dist);

	// printf("hit point -> %lf;%lf\n", hit_pos.x, hit_pos.y);
	// draw_line_on_map(window, player.pos, hit_pos, RED);

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
