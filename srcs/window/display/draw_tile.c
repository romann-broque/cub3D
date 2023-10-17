/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:05:17 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/17 14:18:57 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_tile_side(
	const size_t j,
	const size_t i
	)
{
	return (j == 0 || j == TILE_SIZE - 1 || i == 0 || i == TILE_SIZE - 1);
}

void	draw_tile(
	t_win *const window,
	const size_t x,
	const size_t y
	)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			if (is_ground(window->map, x, y) == true
				|| (is_wall(window->map, x, y) == true
					&& is_tile_side(j, i) == true))
			{
				put_pixel(&(window->data),
					x * (TILE_SIZE - 1) + j,
					y * (TILE_SIZE - 1) + i,
					WHITE);
			}
			++j;
		}
		++i;
	}
}
