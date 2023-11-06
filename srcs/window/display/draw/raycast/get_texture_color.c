/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 08:26:13 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/06 07:58:19 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static unsigned int	get_color_from_text_pos(
	const t_texture texture,
	const t_pos *const tex_pos
	)
{
	const t_data	texture_data = texture.data;
	const int		t_x = (int)tex_pos->x & (texture.width - 1);
	const int		t_y = (int)tex_pos->y & (texture.height - 1);

	return (*(int *)(texture_data.addr
		+ t_y * texture_data.line_length
		+ t_x * texture_data.byte_per_pixel));
}

unsigned int	get_color_from_floor_pos(
	t_win *const window,
	const t_pos *const curr_floor
	)
{
	const t_texture	*floor_texture = window->config.textures + E_FLOOR;
	t_pos			floor_tex_pos;

	floor_tex_pos.x
		= ((int)(curr_floor->x * floor_texture->width))
		% floor_texture->width;
	floor_tex_pos.y
		= ((int)(curr_floor->y * floor_texture->height))
		% floor_texture->height;
	return (get_color_from_text_pos(*floor_texture, &floor_tex_pos));
}

unsigned int	get_color_from_ceil_pos(
	t_win *const window,
	const t_pos *const curr_ceil
	)
{
	const t_texture	*ceil_texture = window->config.textures + E_CEIL;
	t_pos			ceil_tex_pos;
	unsigned int	color;

	ceil_tex_pos.x
		= ((int)(curr_ceil->x * ceil_texture->width))
		% ceil_texture->width;
	ceil_tex_pos.y
		= ((int)(curr_ceil->y * ceil_texture->height))
		% ceil_texture->height;
	color = get_color_from_text_pos(*ceil_texture, &ceil_tex_pos);
	return (change_brightness(color, BRIGHTNESS_FACTOR));
}

unsigned int	get_wall_texture(
	const t_cast *const cast,
	t_texture texture,
	int tex_x
	)
{
	unsigned int	color;
	t_pos			tex_pos;

	set_pos(&tex_pos, tex_x, texture.tex_pos);
	color = get_color_from_text_pos(texture, &tex_pos);
	change_texture_brightness(&color, cast->side);
	return (color);
}
