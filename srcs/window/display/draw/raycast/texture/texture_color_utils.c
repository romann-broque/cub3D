/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_color_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:14:58 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/13 14:16:57 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	change_texture_brightness(
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
