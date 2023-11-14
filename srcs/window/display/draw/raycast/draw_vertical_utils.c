/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:55:09 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/14 10:30:30 by rbroque          ###   ########.fr       */
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

t_texture	*get_texture_from_cast(
	t_texture	textures_array[TEXTURE_COUNT][MAX_TEXTURE_COUNT],
	const t_cast *const cast
)
{
	if (cast->tile->tile_char == WALL)
		return ((textures_array + cast->side)[0]);
	if (is_tile_door(cast->tile) == true)
		return ((textures_array + E_DOOR)[0]);
	return ((textures_array + MANDATORY_ATTRIBUTE_COUNT
			+ index_of(SPECIAL_TILES, cast->tile->tile_char) - 1)[0]);
}

void	set_texture_start_pos(
	t_win *const window,
	const t_cast *const cast,
	const int lineheight,
	const double wall_start_y
)
{
	t_texture *const	texture = get_texture_from_cast(
			window->config.textures, cast);

	texture->step = 1.0 * texture->height / lineheight;
	texture->tex_pos = (wall_start_y - WINDOW_HEIGHT / 2 + lineheight / 2)
		* texture->step;
}
