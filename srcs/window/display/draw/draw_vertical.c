/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:46:43 by jess              #+#    #+#             */
/*   Updated: 2023/10/26 17:19:40 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static unsigned int	get_floor_color(t_win *const window)
{
	return (window->config.floor_color);
}

static unsigned int	get_ceil_color(t_win *const window)
{
	return (window->config.ceil_color);
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

static void	display_ceil_and_floor(
	t_win *const window,
	t_pos wall_end
)
{
	const unsigned int	floor_color = get_floor_color(window);
	const unsigned int	ceil_color = get_ceil_color(window);
	const int			x = (int)wall_end.x;
	int					y;

	if (wall_end.y < 0)
		wall_end.y = WINDOW_HEIGHT;
	y = wall_end.y + 1;
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
	display_ceil_and_floor(window, wall_end);
}
