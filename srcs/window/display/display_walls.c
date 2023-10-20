/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jess <jess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:46:43 by jess              #+#    #+#             */
/*   Updated: 2023/10/20 16:15:25 by jess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_wall	*init_wall(
	t_wall **wall,
	const ssize_t lineheight,
	const ssize_t height
	)
{
	(*wall)->start = (lineheight * NEGATIVE * HALF) + (height * HALF);
	if ((*wall)->start < 0)
		(*wall)->start = 0;
	(*wall)->end = (lineheight * HALF) + (height * HALF);
	if ((*wall)->end >= height)
		(*wall)->end = height + NEGATIVE;
	return (*wall);
}

void	display_walls(
	t_win *const window,
	const ssize_t lineheight,
	const ssize_t height,
	const ssize_t x
	)
{
	ssize_t	i;
	t_wall	*wall;

	wall = init_wall(&wall, lineheight, height);
	i = 0;
	while(i < (wall->end - wall->start))
	{
		put_pixel(&(window->data), x, wall->start + i, BLUE);
		i++;
	}
}
