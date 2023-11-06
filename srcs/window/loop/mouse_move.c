/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jess <jess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:42:39 by lechon            #+#    #+#             */
/*   Updated: 2023/11/06 15:07:48 by jess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	define_window_cursor(t_win *const window)
{
	Display		*display;
	Cursor		invisible_cursor;

	display = XOpenDisplay(NULL);
	if (display == NULL)
		return ;
	invisible_cursor = None;
	if (window->is_mouse_in_window == false)
		display_window_cursor(display, invisible_cursor);
	else
		hide_window_cursor(display, invisible_cursor);
}

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
	define_window_cursor(window);
	if (x == prev_x)
		return (EXIT_SUCCESS);
	else if (x < prev_x)
		rotate_side(&(window->map->player), -ROTATE_SPEED / 3);
	else if (x > prev_x)
		rotate_side(&(window->map->player), ROTATE_SPEED / 3);
	prev_x = x;
	return (EXIT_SUCCESS);
}
