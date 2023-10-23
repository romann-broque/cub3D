/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechon <lechon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:09:13 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/23 10:32:32 by lechon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display_window(t_win *const window)
{
	if (MAP_DISPLAY)
		display_map(window);
	if (MINIMAP_DISPLAY)
		display_minimap(window);
	display_walls(window, 2.42, 500);
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
		window->data.img, 0, 0);
	loop(window);
}
