/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:42:39 by lechon            #+#    #+#             */
/*   Updated: 2023/11/07 12:57:22 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	wrap_mouse_position(t_win *const window, int x, int y)
{
	mlx_mouse_move(window->mlx_ptr, window->win_ptr, x, y);
}

int	mouse_move(int x, __attribute__((unused))int y, t_win *const window)
{
	static int	prev_x = WINDOW_WIDTH / 2;

	if (window->is_mouse_in_window == true)
	{
		wrap_mouse_position(window, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
		if (x == prev_x)
			return (EXIT_SUCCESS);
		else if (x < prev_x)
			rotate_side(&(window->map->player), -ROTATE_SPEED / 3);
		else if (x > prev_x)
			rotate_side(&(window->map->player), ROTATE_SPEED / 3);
		prev_x = x;
	}
	return (EXIT_SUCCESS);
}
