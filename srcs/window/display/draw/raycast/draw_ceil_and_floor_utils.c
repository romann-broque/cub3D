/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceil_and_floor_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 08:26:13 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/27 08:41:52 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_pos	get_floor_wall(
	t_win *const window,
	const t_cast cast
	)
{
	const double	wall_x = get_wall_x(cast);
	const t_pos		player_pos = window->map->player.pos;
	t_pos			floor_wall;

	if (cast.side == EAST_FACE || cast.side == WEST_FACE)
	{
		floor_wall.x = (int)player_pos.x + 1.0;
		floor_wall.y = (int)player_pos.y + wall_x;
		if (cast.ray.x > 0)
		{
			floor_wall.x = (int)player_pos.x;
			floor_wall.y = (int)player_pos.y + wall_x;
		}
	}
	else if (cast.side == NORTH_FACE || cast.side == SOUTH_FACE)
	{
		floor_wall.x = (int)player_pos.x + wall_x;
		floor_wall.y = (int)player_pos.y + 1.0;
		if (cast.ray.y > 0)
		{
			floor_wall.x = (int)player_pos.x + wall_x;
			floor_wall.y = (int)player_pos.y;
		}
	}
	return (floor_wall);
}

t_pos	get_floor_tex_pos(
	t_win *const window,
	const int y,
	const t_pos floor_wall,
	const double perp_wall_dist
	)
{
	const double	current_dist = WINDOW_HEIGHT / (2.0 * y - WINDOW_HEIGHT);
	const double	weight = current_dist / perp_wall_dist;
	const t_pos		player_pos = window->map->player.pos;
	t_pos			curr_floor;
	t_pos			floor_tex_pos;

	curr_floor.x = weight * floor_wall.x + (1.0 - weight) * (int)player_pos.x;
	curr_floor.y = weight * floor_wall.y + (1.0 - weight) * (int)player_pos.y;
	if (y == 0 || y == WINDOW_HEIGHT)
	{
		printf("weight -> %lf\n", weight);
	}
	floor_tex_pos.x = ((int)
			(curr_floor.x * window->config.textures[E_FLOOR].width))
		% window->config.textures[E_FLOOR].width;
	floor_tex_pos.y = ((int)
			(curr_floor.y * window->config.textures[E_FLOOR].height))
		% window->config.textures[E_FLOOR].height;
	return (floor_tex_pos);
}

unsigned int	get_color_from_floor_tex_pos(
	t_win *const window,
	const t_pos floor_tex_pos
	)
{
	const t_data	floor_texture_data = window->config.textures[E_FLOOR].data;

	return (*(int *)(floor_texture_data.addr
		+ floor_texture_data.line_length * (int)floor_tex_pos.y
		+ (int)floor_tex_pos.x
		* (floor_texture_data.bits_per_pixel / BITS_PER_BYTE)));
}
