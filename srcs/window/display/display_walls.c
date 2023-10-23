/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechon <lechon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:46:43 by jess              #+#    #+#             */
/*   Updated: 2023/10/23 14:12:48 by lechon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_wall_color(const t_side side, const int color)
{
	if (side == Y_SIDE)
		return (color / 2);
	return (color);
}

static t_pos	init_wall_end(
	const int lineheight,
	const int height,
	const int x
	)
{
	t_pos		wall;
	const int	tmp1 = lineheight / 2;
	const int	tmp2 = height / 2;

	wall.y = tmp1 + tmp2;
	if (wall.y >= height)
		wall.y = height - 1;
	wall.x = x;
	return (wall);
}

static t_pos	init_wall_start(
	const int lineheight,
	const int height,
	const int x
	)
{
	t_pos		wall;
	const int	tmp1 = (lineheight * -1) / 2;
	const int	tmp2 = height / 2;

	wall.y = tmp1 + tmp2;
	if (wall.y < 0)
		wall.y = 0;
	wall.x = x;
	return (wall);
}

void	display_walls(
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

	i = wall_start.y;
	while(i < wall_end.y)
	{
		put_pixel(&(window->data), x, i, get_wall_color(side, GREEN));
		i++;
	}
}
