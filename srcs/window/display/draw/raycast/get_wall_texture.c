/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:05:50 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/28 16:03:04 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	get_wall_x(const t_cast cast)
{
	double	wall_x;

	if (cast.side == WEST_FACE || cast.side == EAST_FACE)
		wall_x = cast.hitpoint.y;
	else
		wall_x = cast.hitpoint.x;
	wall_x = 1 - wall_x + floor(wall_x);
	return (wall_x);
}

int	get_tex_x(
	const t_cast cast,
	const t_texture texture
	)
{
	const double	wall_x = get_wall_x(cast);
	const bool		is_pole_dir
		= (cast.side == NORTH_FACE
			|| cast.side == SOUTH_FACE);
	int				tex_x;

	tex_x = (int)(wall_x * (double)texture.width);
	if ((is_pole_dir == false && cast.ray.x > 0)
		|| (is_pole_dir == true && cast.ray.y < 0))
	{
		tex_x = texture.width - tex_x - 1;
	}
	return (tex_x);
}

static void	change_texture_brightness(
	unsigned int *const color,
	const t_side side
	)
{
	if (side == EAST_FACE)
		*color
			= change_brightness(*color, BRIGHTNESS_FACTOR * BRIGHTNESS_POWER);
	else if (side == NORTH_FACE || side == SOUTH_FACE)
		*color = change_brightness(*color, BRIGHTNESS_FACTOR);
}

int	get_wall_texture(
	const t_cast cast,
	t_texture texture,
	const int tex_x
	)
{
	const int		tex_y = (int)texture.tex_pos & (texture.height - 1);
	unsigned int	color;

	color = *(int *)(texture.data.addr
			+ texture.data.line_length * tex_y
			+ tex_x * texture.data.bits_per_pixel / BITS_PER_BYTE);
	change_texture_brightness(&color, cast.side);
	return (color);
}
