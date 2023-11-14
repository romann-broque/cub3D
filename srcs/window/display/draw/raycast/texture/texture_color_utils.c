/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_color_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:14:58 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/14 16:54:20 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	apply_darkness(
	unsigned int *const color,
	const double dist,
	const bool is_dark
	)
{
	unsigned int	new_color;

	if (is_dark == true)
	{
		new_color = change_brightness(*color, 1 / (DARK_COEFF * dist));
		if (*color > new_color)
			*color = new_color;
	}
}

void	change_texture_brightness(
	unsigned int *const color,
	const t_cast *const cast
	)
{
	if (cast->side == EAST_FACE)
		*color
			= change_brightness(*color, BRIGHTNESS_FACTOR * BRIGHTNESS_POWER);
	else if (cast->side == NORTH_FACE || cast->side == SOUTH_FACE)
		*color = change_brightness(*color, BRIGHTNESS_FACTOR);
}

unsigned int	get_color_from_text_pos(
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
