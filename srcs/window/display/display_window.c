/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:09:13 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/19 14:56:42 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display_window(t_win *const window)
{
	raycaster(window);
	if (MAP_DISPLAY)
		display_map(window);
	if (MINIMAP_DISPLAY)
		display_minimap(window);
	display_player(window);
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
		window->data.img, 0, 0);
	loop(window);
}
