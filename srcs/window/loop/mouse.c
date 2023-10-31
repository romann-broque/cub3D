/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechon <lechon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:42:39 by lechon            #+#    #+#             */
/*   Updated: 2023/10/31 15:41:07 by lechon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	wrap_mouse_position(t_win *const window, int x, int y)
{
	if (x > WINDOW_WIDTH - MOUSE_DIST_EDGE)
	{
		x = MOUSE_DIST_EDGE;
		mlx_mouse_move(window->mlx_ptr, window->win_ptr, x, y);
	}
	if (x < MOUSE_DIST_EDGE)
	{
		x = WINDOW_WIDTH - MOUSE_DIST_EDGE;
		mlx_mouse_move(window->mlx_ptr, window->win_ptr, x, y);
	}
}

int	mouse_move(int x, int y, t_win *const window)
{
	static int	prev_x = WINDOW_WIDTH / 2;

	wrap_mouse_position(window, x, y);
	if (x == prev_x)
		return (EXIT_SUCCESS);
	else if (x < prev_x)
		rotate_side(&(window->map->player), -ROTATE_SPEED / 2);
	else if (x > prev_x)
		rotate_side(&(window->map->player), ROTATE_SPEED / 2);
	prev_x = x;
	return (EXIT_SUCCESS);
}
