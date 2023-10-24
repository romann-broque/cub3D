/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:55:09 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/23 15:57:24 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_wall_color(const t_side side, const int color)
{
	if (side == Y_SIDE)
		return (color / 2);
	return (color);
}

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
