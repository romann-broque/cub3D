/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceil_and_floor_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 08:26:13 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/28 16:03:17 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_pos	get_floor_pos(
	t_win *const window,
	const int y,
	const t_pos floor_wall,
	const double perp_wall_dist
	)
{
	const double	weight = WINDOW_HEIGHT
		/ ((2.0 * y - WINDOW_HEIGHT) * (0.000001 + perp_wall_dist));
	const t_pos		player_pos = window->map->player.pos;
	t_pos			curr_floor;

	curr_floor.x = weight * (floor_wall.x - player_pos.x) + player_pos.x;
	curr_floor.y = weight * (floor_wall.y - player_pos.y) + player_pos.y;
	return (curr_floor);
}

static unsigned int	get_color_from_text_pos(
	const t_texture texture,
	const t_pos tex_pos
	)
{
	const t_data	texture_data = texture.data;
	const int		t_x = (int)tex_pos.x;
	const int		t_y = (int)tex_pos.y & (texture.height - 1);

	return (*(int *)(texture_data.addr
		+ t_y * texture_data.line_length
		+ t_x * texture_data.bits_per_pixel / BITS_PER_BYTE));
}

unsigned int	get_color_from_floor_pos(
	t_win *const window,
	const t_pos curr_floor
	)
{
	const t_texture	floor_texture = window->config.textures[E_FLOOR];
	t_pos			floor_tex_pos;

	floor_tex_pos.x
		= ((int)(curr_floor.x * floor_texture.width))
		% floor_texture.width;
	floor_tex_pos.y
		= ((int)(curr_floor.y * floor_texture.height))
		% floor_texture.height;
	return (get_color_from_text_pos(floor_texture, floor_tex_pos));
}

unsigned int	get_color_from_ceil_pos(
	t_win *const window,
	const t_pos curr_ceil
	)
{
	const t_texture	ceil_texture = window->config.textures[E_CEIL];
	t_pos			ceil_tex_pos;

	ceil_tex_pos.x
		= ((int)(curr_ceil.x * ceil_texture.width))
		% ceil_texture.width;
	ceil_tex_pos.y
		= ((int)(curr_ceil.y * ceil_texture.height))
		% ceil_texture.height;
	return (get_color_from_text_pos(ceil_texture, ceil_tex_pos));
}
