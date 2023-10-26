/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechon <lechon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:05:50 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/26 11:20:04 by lechon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture	*get_texture_from_side(
	t_texture	textures_array[TEXTURE_COUNT],
	const t_side side
)
{
	if (side == X_SIDE)
		return (textures_array + E_WEST);
	return (textures_array + E_SOUTH);
}

static int	get_tex_x(
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

static double	get_wall_x(const t_cast cast)
{
	double	wall_x;

	if (cast.side == X_SIDE)
		wall_x = cast.hitpoint.y;
	else
		wall_x = cast.hitpoint.x;
	wall_x -= (floor(wall_x));
	return (wall_x);
}

int	get_wall_texture(
	const t_cast cast,
	t_texture texture
	)
{
	const double	wall_x = get_wall_x(cast);
	const int		tex_x = get_tex_x(cast, wall_x, texture);
	const int		tex_y = (int)texture.tex_pos & (texture.height - 1);
	int				color;

	color = *(int *)(texture.data.addr
			+ texture.data.line_length * tex_y
			+ tex_x * texture.data.bits_per_pixel / 8);
	if (cast.side == Y_SIDE)
		color = (color >> 1);
	return (color);
}

void	set_texture_start_pos(
	t_win *const window,
	const t_cast cast,
	const int lineheight,
	const double wall_start_y
)
{
	t_texture *const	texture = get_texture_from_side(
			window->config.textures, cast.side);

	texture->step = 1.0 * texture->height / lineheight;
	texture->tex_pos = (wall_start_y - WINDOW_HEIGHT / 2 + lineheight / 2)
		* texture->step;
}