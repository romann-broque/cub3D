/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:55:09 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/25 22:20:37 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_tex_x(
	const t_cast cast,
	const double wall_x,
	const t_texture texture
	)
{
	int		tex_x;

	tex_x = (int)(wall_x * (double)texture.width);
	if ((cast.side == 0 && cast.ray.x > 0)
		|| (cast.side == 1 && cast.ray.y < 0))
		tex_x = texture.width - tex_x - 1;
	return (tex_x);
}

double	get_wall_x(const t_cast cast)
{
	double	wall_x;

	if (cast.side == X_SIDE)
		wall_x = cast.hitpoint.y;
	else
		wall_x = cast.hitpoint.x;
	wall_x -= (floor(wall_x));
	return (wall_x);
}

/*
// tex_ doit etre calcule en amont de la boucle
*/

int	get_wall_texture(
	const t_cast cast,
	t_texture texture
	)
{
	const double	wall_x = get_wall_x(cast);
	const int		tex_x = get_tex_x(cast, wall_x, texture);
	const int		tex_y = (int)texture.tex_pos & (texture.height - 1);
	int				color;

	color = *(int *)(texture.content
			+ texture.height * tex_y + tex_x * texture.width);
	if (cast.side == Y_SIDE)
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
