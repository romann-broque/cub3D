/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:05:50 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/06 22:41:42 by rbroque          ###   ########.fr       */
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

static int	get_new_tex_pos_door(
	const t_texture texture,
	const t_cast *const cast,
	const int tex_x

)
{
	double	offset;
	int		new_tex_pos;

	new_tex_pos = tex_x;
	if (is_tile_door(cast->tile) == true)
	{
		offset = 0;
		if (cast->tile->state == OPENING || cast->tile->state == CLOSING)
		{
			offset = cast->tile->progression;
			if (cast->side == EAST_FACE || cast->side == SOUTH_FACE)
				offset *= -1;
		}
		else if (cast->tile->state == OPENED)
			offset = 1;
		new_tex_pos += (texture.width * offset);
	}
	return (new_tex_pos);
}

static bool	can_door_be_displayed(
	const t_cast *const cast
)
{
	return ((cast->tile->tile_char == DOOR_VERT
			&& (cast->side == NORTH_FACE || cast->side == SOUTH_FACE))
		|| (cast->tile->tile_char == DOOR_HOR
			&& (cast->side == EAST_FACE || cast->side == WEST_FACE)));
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
	if (BONUS == true && is_tile_door(cast->tile) == true)
	{
		if (can_door_be_displayed(cast) == true)
			tex_x = get_new_tex_pos_door(texture, cast, tex_x);
		else
			tex_x = -1;
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
