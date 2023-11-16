/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 06:15:38 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/09 13:40:28 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_square(
	t_win *const window,
	const t_pos *const screen_pos,
	const size_t size,
	const int color
	)
{
	const int	x_screen = screen_pos->x;
	const int	y_screen = screen_pos->y;
	size_t		i;
	size_t		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			put_tile_pixel(window, x_screen + j, y_screen + i, color);
			put_tile_pixel(window, x_screen - j, y_screen + i, color);
			put_tile_pixel(window, x_screen + j, y_screen - i, color);
			put_tile_pixel(window, x_screen - j, y_screen - i, color);
			++j;
		}
		++i;
	}
}
