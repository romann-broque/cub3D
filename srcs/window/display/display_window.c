/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:09:13 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/15 15:57:51 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	display_fov(
	t_win *const window,
	t_pos hitpoint_array[WINDOW_WIDTH]
	)
{
	const t_pos *const	player_pos = &(window->map->player.pos);
	size_t				i;

	i = 0;
	while (i < WINDOW_WIDTH)
	{
		if (BONUS)
		{
			if (window->mod == E_MAP)
				draw_line_on_map(window, player_pos, hitpoint_array + i, BLUE);
			else if (window->mod == E_STD)
				draw_line_on_minimap(window, player_pos,
					hitpoint_array + i, BLUE);
		}
		++i;
	}
}

static void	display_map_or_minimap(t_win *const window)
{
	if (window->mod == E_MAP)
		display_map(window);
	else if (window->mod == E_STD)
		display_minimap(window);
}

void	display_window_content(t_win *const window)
{
	t_pos	hitpoint_array[WINDOW_WIDTH];
	double	distance_array[WINDOW_WIDTH];

	raycaster(window, hitpoint_array, distance_array);
	if (BONUS)
	{
		display_sprites(window, distance_array);
		display_map_or_minimap(window);
		display_fov(window, hitpoint_array);
		display_sprites_on_map(window);
		display_player(window);
		refresh_tiles(window->map);
		refresh_sprites(window->map);
		print_fps();
	}
}

void	display_window(t_win *const window)
{
	display_window_content(window);
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
		window->data.img, 0, 0);
	loop(window);
}
