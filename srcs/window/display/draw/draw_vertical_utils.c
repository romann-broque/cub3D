/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechon <lechon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:55:09 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/25 17:30:27 by lechon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_tex_x(
	const t_side side,
	const t_player player,
	const double wallx,
	const t_texture texture
	)
{
	int		tex_x;

	tex_x = (int)(wallx * (double)texture->width);
	if ((side == 0 && player.dir.x > 0) || (side == 1 && player.dir.y < 0))
		tex_x = texture->width - tex_x - 1;
	return (tex_x);
}

	/* wallx = hitpoint.x; */
	/* wallx = hitpoint.y; */

double	get_wallx(
	const t_side side,
	const t_player player,
	const double perp_wall_dist
	)
{
	double	wallx;

	if (side == 0)
		wallx = player.pos.y + perp_wall_dist + player.dir.y;
	else
		wallx = player.pos.x + perp_wall_dist + player.dir.x;
	wallx = -(floor(wallx));
	return (wallx);
}

int	get_wall_texture(
	t_win *const window,
	const t_side side,
	const double perp_wall_dist,
	const t_texture texture
	)
{
	const t_player	player = window->map->player;
	const double	wallx = get_wallx(side, player, perp_wall_dist);
	const int		tex_x = get_texx(side, player, wallx, texture);
	const int		tex_y = (int)texture->tex_pos & (texture->height - 1);
	const int		color;

	color = texture[side][texture->height * tex_y + tex_x];
	if (side == Y_SIDE)
		color = (color >> 1);
	return (color);
}
/*
int	get_wall_color(const t_side side, const int color)
{
	if (side == Y_SIDE)
		return (color / 2);
	return (color);
}
*/

t_pos	init_wall_end(
	const int lineheight,
	const int height,
	const int x
	)
{
	t_pos		wall;

	wall.y = (lineheight / 2) + (height / 2);
	if (wall.y >= height)
		wall.y = fmin((height - 1), wall.y);
	wall.x = x;
	return (wall);
}

t_pos	init_wall_start(
	const int lineheight,
	const int height,
	const int x
	)
{
	t_pos		wall;

	wall.y = (-lineheight / 2) + (height / 2);
	if (wall.y < 0)
		wall.y = fmax(0.0, wall.y);
	wall.x = x;
	return (wall);
}
