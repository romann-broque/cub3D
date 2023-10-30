/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:55:09 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/28 21:06:07 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

t_texture	*get_texture_from_side(
	t_texture	textures_array[TEXTURE_COUNT],
	const t_side side
)
{
	return (textures_array + side);
}

void	set_texture_start_pos(
	t_win *const window,
	const t_side side,
	const int lineheight,
	const double wall_start_y
)
{
	t_texture *const	texture = get_texture_from_side(
			window->config.textures, side);

	texture->step = 1.0 * texture->height / lineheight;
	texture->tex_pos = (wall_start_y - WINDOW_HEIGHT / 2 + lineheight / 2)
		* texture->step;
}
