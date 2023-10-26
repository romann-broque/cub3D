/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechon <lechon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:46:43 by jess              #+#    #+#             */
/*   Updated: 2023/10/26 11:21:02 by lechon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	display_ceil(
	t_win *const window,
	const int x,
	const int max_y
)
{
	const int	color = window->config.ceil_color;
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
	const int	color = window->config.floor_color;
	int			i;

	i = min_y;
	while (i < WINDOW_HEIGHT - 1)
	{
		put_pixel(&(window->data), x, i, color);
		++i;
	}
}

static void	display_wall(
	t_win *const window,
	const t_cast cast,
	const t_pos wall_start,
	const t_pos wall_end
)
{
	const int			x = wall_start.x;
	t_texture *const	texture = get_texture_from_side(
			window->config.textures, cast.side);
	t_texture			texture_cpy;
	int					i;

	texture_cpy = *texture;
	i = wall_start.y;
	while (i < wall_end.y)
	{
		put_pixel(&(window->data), x, i,
			get_wall_texture(cast, texture_cpy));
		texture_cpy.tex_pos += texture_cpy.step;
		++i;
	}
}

void	draw_vertical(
	t_win *const window,
	const t_cast cast,
	const double perp_wall_dist,
	const int x
	)
{
	const int	lineheight = WINDOW_HEIGHT / perp_wall_dist;
	const t_pos	wall_start = init_wall_start(lineheight, WINDOW_HEIGHT, x);
	const t_pos	wall_end = init_wall_end(lineheight, WINDOW_HEIGHT, x);

	display_ceil(window, x, wall_start.y);
	set_texture_start_pos(window, cast, lineheight, wall_start.y);
	display_wall(window, cast, wall_start, wall_end);
	display_floor(window, x, wall_end.y);
}
