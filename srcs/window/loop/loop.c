/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jess <jess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:43:23 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/06 15:08:35 by jess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	hook(t_win *const window)
{
	mlx_hook(window->win_ptr, DestroyNotify, StructureNotifyMask, close_window,
		window);
	mlx_hook(window->win_ptr, KeyPress, KeyPressMask, key_press, window);
	mlx_hook(window->win_ptr, KeyRelease, KeyReleaseMask, key_release, window);
	if (BONUS == true)
	{
		mlx_hook(window->win_ptr, ButtonPress,
			ButtonPressMask, mouse_click, window);
		mlx_hook(window->win_ptr, MotionNotify,
			PointerMotionMask, mouse_move, window);
	}
}

void	loop(t_win *const window)
{
	hook(window);
	mlx_loop_hook(window->mlx_ptr, browse_mapping, window);
	mlx_loop(window->mlx_ptr);
}
