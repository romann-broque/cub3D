/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:03:33 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/31 15:59:12 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->byte_per_pixel));
	*(unsigned int *)dst = color;
}

void	put_pixel(t_data *data, const int x, const int y, const int color)
{
	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
		my_mlx_pixel_put(data, x, y, color);
}

static void	put_pixel_on_minimap(
	t_win *const window,
	const size_t x,
	const size_t y,
	const unsigned int color
)
{
	static const double	min_x = MINIMAP_XOFFSET;
	static const double	max_x = MINIMAP_XOFFSET
		+ 2 * MINIMAP_RADIUS * TILE_SIZE + TILE_SIZE;
	static const double	min_y = MINIMAP_YOFFSET;
	static const double	max_y = MINIMAP_YOFFSET
		+ 2 * MINIMAP_RADIUS * TILE_SIZE + TILE_SIZE;

	if (x >= min_x && x < max_x
		&& y >= min_y && y < max_y)
	{
		put_pixel(&(window->data),
			x, y, color);
	}
}

void	put_tile_pixel(
	t_win *const window,
	const size_t x,
	const size_t y,
	const unsigned int color
)
{
	const enum e_mod	mod = window->mod;

	if (mod == E_STD)
		put_pixel_on_minimap(window,
			x, y, color);
	else if (mod == E_MAP)
		put_pixel(&(window->data),
			x, y, color);
}
