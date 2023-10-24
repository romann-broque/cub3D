/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:09:13 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/24 15:41:05 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	display_fov(
	t_win *const window,
	const t_pos hitpoint_array[WINDOW_WIDTH]
	)
{
	const t_pos	player_pos = window->map->player.pos;
	size_t		i;

	i = 0;
	while (i < WINDOW_WIDTH)
	{
		if (MAP_DISPLAY && window->mod == E_MAP)
			draw_line_on_map(window, player_pos, hitpoint_array[i], BLUE);
		if (MINIMAP_DISPLAY && window->mod == E_STD)
			draw_line_on_minimap(window, player_pos, hitpoint_array[i], BLUE);
		++i;
	}
}

void	display_window_content(t_win *const window)
{
	t_pos	hitpoint_array[WINDOW_WIDTH];

	raycaster(window, hitpoint_array);
	if (MAP_DISPLAY && window->mod == E_MAP)
		display_map(window);
	if (MINIMAP_DISPLAY && window->mod == E_STD)
		display_minimap(window);
	display_fov(window, hitpoint_array);
}

void	display_window(t_win *const window)
{
	display_window_content(window);
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
		window->data.img, 0, 0);
	loop(window);
}
