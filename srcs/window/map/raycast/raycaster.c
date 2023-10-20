/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:46:36 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/20 23:32:38 by rbroque          ###   ########.fr       */
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

static int	get_sign(const double x)
{
	if (x < 0)
		return (-1);
	return (1);
}

static t_vect	get_ray_dir(const t_vect dir, const t_vect ray)
{
	t_vect	ray_dir;

	ray_dir.x = 0;
	ray_dir.y = 0;
	if (dir.x != 0)
	{
		ray_dir.x = dir.x;
		ray_dir.y = get_sign(ray.y);
	}
	if (dir.y != 0)
	{
		ray_dir.x = get_sign(ray.x);
		ray_dir.y = dir.y;
	}
	printf("RAY_DIR_X -> %lf\n", ray_dir.x);
	printf("RAY_DIR_Y -> %lf\n", ray_dir.y);
	return (ray_dir);
}

static t_pos	find_hit_pos(
	const t_player player,
	const t_vect ray,
	const t_vect cast_dist
)
{
	const t_vect	ray_dir = get_ray_dir(player.dir, ray);
	const double	x_ray = ray_dir.x * cast_dist.x;
	const double	y_ray = ray_dir.y * cast_dist.y;
	double			x;
	double			y;
	t_pos			hit_pos;

	x = player.pos.x;
	y = player.pos.y;
	if (fabs(x_ray) < MAX_LEN_RAY)
		x = player.pos.x + x_ray;
	if (fabs(y_ray) < MAX_LEN_RAY)
		y = player.pos.y + y_ray;
	printf("ray.x -> %lf\n", ray.x);
	printf("ray.y -> %lf\n", ray.y);
	printf("cast.x -> %lf\n", cast_dist.x);
	printf("cast.y -> %lf\n", cast_dist.y);
	printf("x_ray -> %lf\n", x_ray);
	printf("y_ray -> %lf\n", y_ray);
	printf("x -> %lf\n", x);
	printf("y -> %lf\n", y);
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
	t_pos	hit_pos = find_hit_pos(player, ray, cast.dist);
		draw_line_on_map(window, hit_pos, player.pos, RED);	
	printf("dist -> %lf;%lf\n", cast.dist.x, cast.dist.y);
	printf("hit point -> %lf;%lf\n", hit_pos.x, hit_pos.y);
	(void)perp_wall_dist;
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
