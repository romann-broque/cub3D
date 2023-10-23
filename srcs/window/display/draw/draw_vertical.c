/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:46:43 by jess              #+#    #+#             */
/*   Updated: 2023/10/23 16:47:31 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	display_ceil(
	t_win *const window,
	const int x,
	const int max_y
)
{
	const int	color = window->config->ceil_color;
	int			i;

	i = 0;
	while (i < max_y)
	{
		put_pixel(&(window->data), x, i, color);
		++i;
	}
}

static void	display_floor(
	t_win *const window,
	const int x,
	const int min_y
)
{
	const int	color = window->config->floor_color;
	int			i;

	i = min_y;
	while (i < WINDOW_HEIGHT)
	{
		put_pixel(&(window->data), x, i, color);
		++i;
	}
}

void	draw_vertical(
	t_win *const window,
	const t_side side,
	const double perp_wall_dist,
	const int x
	)
{
	const int	lineheight = WINDOW_HEIGHT / perp_wall_dist;
	const t_pos	wall_start = init_wall_start(lineheight, WINDOW_HEIGHT, x);
	const t_pos	wall_end = init_wall_end(lineheight, WINDOW_HEIGHT, x);
	int			i;

	display_ceil(window, x, wall_start.y);
	i = wall_start.y;
	while (i < wall_end.y)
	{
		put_pixel(&(window->data), x, i, get_wall_color(side, RED));
		++i;
	}
	display_floor(window, x, wall_end.y);
}
