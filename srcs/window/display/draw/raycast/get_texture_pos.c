/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:05:50 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/28 22:11:20 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	get_wall_x(const t_cast *const cast)
{
	double	wall_x;

	if (cast->side == WEST_FACE || cast->side == EAST_FACE)
		wall_x = cast->hitpoint.y;
	else
		wall_x = cast->hitpoint.x;
	wall_x = 1 - wall_x + floor(wall_x);
	return (wall_x);
}

int	get_tex_x(
	const t_cast *const cast,
	const t_texture texture
	)
{
	const double	wall_x = get_wall_x(cast);
	const bool		is_pole_dir
		= (cast->side == NORTH_FACE
			|| cast->side == SOUTH_FACE);
	int				tex_x;

	tex_x = (int)(wall_x * (double)texture.width);
	if ((is_pole_dir == false && cast->ray.x > 0)
		|| (is_pole_dir == true && cast->ray.y < 0))
	{
		tex_x = texture.width - tex_x - 1;
	}
	return (tex_x);
}

t_pos	get_floor_pos(
	t_win *const window,
	const int y,
	const t_pos *floor_wall,
	const double perp_wall_dist
	)
{
	const double	weight = WINDOW_HEIGHT
		/ ((2.0 * y - WINDOW_HEIGHT) * (1e-10 + perp_wall_dist));
	const t_pos		*player_pos = &(window->map->player.pos);
	t_pos			curr_floor;

	curr_floor.x = weight * (floor_wall->x - player_pos->x) + player_pos->x;
	curr_floor.y = weight * (floor_wall->y - player_pos->y) + player_pos->y;
	return (curr_floor);
}
