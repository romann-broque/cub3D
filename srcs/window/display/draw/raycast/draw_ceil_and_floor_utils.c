/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceil_and_floor_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 08:26:13 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/28 15:46:06 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_pos	get_floor_tex_pos(
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
	t_pos			floor_tex_pos;

	curr_floor.x = weight * (floor_wall.x - player_pos.x) + player_pos.x;
	curr_floor.y = weight * (floor_wall.y - player_pos.y) + player_pos.y;
	floor_tex_pos.x
		= ((int)(curr_floor.x * window->config.textures[E_FLOOR].width))
		% window->config.textures[E_FLOOR].width;
	floor_tex_pos.y
		= ((int)(curr_floor.y * window->config.textures[E_FLOOR].height))
		% window->config.textures[E_FLOOR].height;
	return (floor_tex_pos);
}

unsigned int	get_color_from_floor_tex_pos(
	t_win *const window,
	const t_pos floor_tex_pos
	)
{
	const t_texture	floor_texture = window->config.textures[E_FLOOR];
	const t_data	floor_texture_data = floor_texture.data;
	const int		t_x = (int)floor_tex_pos.x;
	const int		t_y = (int)floor_tex_pos.y & (floor_texture.height - 1);

	return (*(int *)(floor_texture_data.addr
		+ t_y * floor_texture_data.line_length
		+ t_x * floor_texture_data.bits_per_pixel / BITS_PER_BYTE));
}
