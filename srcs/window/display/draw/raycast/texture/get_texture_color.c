/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 08:26:13 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/14 15:29:36 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	get_color_from_floor_pos(
	t_win *const window,
	const t_cast *const cast,
	const t_pos *const curr_floor
	)
{
	const t_texture	*floor_texture = (window->config.textures + E_FLOOR)[0];
	t_pos			floor_tex_pos;
	unsigned int	color;

	floor_tex_pos.x
		= ((int)(curr_floor->x * floor_texture->width))
		% floor_texture->width;
	floor_tex_pos.y
		= ((int)(curr_floor->y * floor_texture->height))
		% floor_texture->height;
	color = get_color_from_text_pos(*floor_texture, &floor_tex_pos);
	change_texture_brightness(&color, cast, window->config.is_dark);
	return (color);
}

unsigned int	get_color_from_ceil_pos(
	t_win *const window,
	const t_cast *const cast,
	const t_pos *const curr_ceil
	)
{
	const t_texture	*ceil_texture = (window->config.textures + E_CEIL)[0];
	t_pos			ceil_tex_pos;
	unsigned int	color;

	ceil_tex_pos.x
		= ((int)(curr_ceil->x * ceil_texture->width))
		% ceil_texture->width;
	ceil_tex_pos.y
		= ((int)(curr_ceil->y * ceil_texture->height))
		% ceil_texture->height;
	color = get_color_from_text_pos(*ceil_texture, &ceil_tex_pos);
	color = change_brightness(color, BRIGHTNESS_FACTOR);
	change_texture_brightness(&color, cast, window->config.is_dark);
	return (color);
}

unsigned int	get_wall_texture(
	const t_cast *const cast,
	t_texture texture,
	const int tex_x,
	t_config *const config
	)
{
	unsigned int	color;
	t_pos			tex_pos;

	set_pos(&tex_pos, tex_x, texture.tex_pos);
	color = get_color_from_text_pos(texture, &tex_pos);
	change_texture_brightness(&color, cast, config->is_dark);
	return (color);
}

unsigned int	get_sprite_texture(
	const t_texture *const texture,
	t_pos tex_pos
	)
{
	return (get_color_from_text_pos(*texture, &tex_pos));
}
