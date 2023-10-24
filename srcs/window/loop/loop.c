/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:43:23 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/24 22:42:27 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	hook(t_win *const window)
{
	mlx_hook(window->win_ptr, DestroyNotify, StructureNotifyMask, close_window,
		window);
	mlx_hook(window->win_ptr, KeyPress, KeyPressMask, key_press, window);
}

void	loop(t_win *const window)
{
	hook(window);
	mlx_loop(window->mlx_ptr);
}
