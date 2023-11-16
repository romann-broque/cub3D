/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:21:13 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/15 09:43:21 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_color(t_config *const config)
{
	config->ceil_color = get_color_from_rgb(
			config->attribute_array[E_CEIL][0]);
	config->floor_color = get_color_from_rgb(
			config->attribute_array[E_FLOOR][0]);
}

unsigned int	change_brightness(const unsigned int color, const double factor)
{
	const unsigned int	red = ((color >> 16) & 0xFF) * factor;
	const unsigned int	green = ((color >> 8) & 0xFF) * factor;
	const unsigned int	blue = (color & 0xFF) * factor;
	const unsigned int	new_color = (red << 16) | (green << 8) | blue;

	return (new_color);
}
