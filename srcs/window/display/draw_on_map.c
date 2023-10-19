/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_on_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:52:26 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/19 15:32:16 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_square_on_map(
	t_win *const window,
	const t_pos pos,
	const size_t size,
	const int color
	)
{
	const double	scale = TILE_SIZE - 1;
	const int		x_screen = (int)(pos.x * scale);
	const int		y_screen = (int)(pos.y * scale);
	size_t			i;
	size_t			j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			put_pixel(&(window->data), x_screen + j, y_screen + i, color);
			put_pixel(&(window->data), x_screen - j, y_screen + i, color);
			put_pixel(&(window->data), x_screen + j, y_screen - i, color);
			put_pixel(&(window->data), x_screen - j, y_screen - i, color);
			++j;
		}
		++i;
	}
}

void	draw_pos_on_map(
	t_win *const window,
	const t_pos pos,
	const int color
	)
{
	const double	scale = TILE_SIZE - 1;
	const int		x_screen = (int)(pos.x * scale);
	const int		y_screen = (int)(pos.y * scale);

	put_pixel(&(window->data), x_screen, y_screen, color);
}

void	draw_coordinate_on_map(
	t_win *const window,
	const double x,
	const double y,
	const int color
	)
{
	const double	scale = TILE_SIZE - 1;
	const int		x_screen = (int)(x * scale);
	const int		y_screen = (int)(y * scale);

	put_pixel(&(window->data), x_screen, y_screen, color);
}
