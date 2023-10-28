/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:46:43 by jess              #+#    #+#             */
/*   Updated: 2023/10/28 16:57:30 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	display_wall(
	t_win *const window,
	const t_cast cast,
	const t_pos wall_start,
	const t_pos wall_end
)
{
	t_texture *const	texture = get_texture_from_side(
			window->config.textures, cast.side);
	const int			tex_x = get_tex_x(cast, *texture);
	const int			x = wall_start.x;
	int					i;
	t_texture			texture_cpy;

	texture_cpy = *texture;
	i = wall_start.y;
	while (i < wall_end.y)
	{
		put_pixel(&(window->data), x, i,
			get_wall_texture(cast, texture_cpy, tex_x));
		texture_cpy.tex_pos += texture_cpy.step;
		++i;
	}
}

static void	display_ceil_and_floor_texture(
	t_win *const window,
	t_pos wall_end,
	const t_cast cast,
	const double perp_wall_dist
)
{
	const t_pos	floor_wall = cast.hitpoint;
	const int	x = (int)wall_end.x;
	int			y;
	t_pos		floor_pos;

	if (wall_end.y < 0)
		wall_end.y = WINDOW_HEIGHT;
	y = wall_end.y;
	while (y < WINDOW_HEIGHT)
	{
		floor_pos = get_floor_pos(window, y,
				floor_wall, perp_wall_dist);
		put_pixel(&(window->data), x, y,
			get_color_from_floor_pos(window, floor_pos));
		put_pixel(&(window->data), x, WINDOW_HEIGHT - y,
			get_color_from_ceil_pos(window, floor_pos));
		++y;
	}
}

static void	display_ceil_and_floor_rgb(
	t_win *const window,
	t_pos wall_end
	)
{
	const unsigned int	floor_color = window->config.floor_color;
	const unsigned int	ceil_color = window->config.ceil_color;
	const int			x = (int)wall_end.x;
	int					y;

	if (wall_end.y < 0)
		wall_end.y = WINDOW_HEIGHT;
	y = wall_end.y;
	while (y < WINDOW_HEIGHT + 1)
	{
		put_pixel(&(window->data), x, y, floor_color);
		put_pixel(&(window->data), x, WINDOW_HEIGHT - y, ceil_color);
		++y;
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

	set_texture_start_pos(window, cast, lineheight, wall_start.y);
	display_wall(window, cast, wall_start, wall_end);
	if (BONUS == true)
		display_ceil_and_floor_texture(window, wall_end, cast, perp_wall_dist);
	else
		display_ceil_and_floor_rgb(window, wall_end);
}
