/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_screen_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:05:42 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/31 15:23:23 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_pos	find_map_screen_pos(
	t_win *const window,
	const t_pos *const pos)
{
	static const double	scale = TILE_SIZE;
	const t_pos			player_pos = window->map->player.pos;
	const double		x_screen = (pos->x - player_pos.x)
		* scale + WINDOW_WIDTH / 2;
	const double		y_screen = (pos->y - player_pos.y)
		* scale + WINDOW_HEIGHT / 2;
	t_pos				screen_pos;

	set_pos(&screen_pos, x_screen, y_screen);
	return (screen_pos);
}

t_pos	find_minimap_screen_pos(
	t_win *const window,
	const t_pos *const pos)
{
	static const double	scale = TILE_SIZE;
	const t_pos			player_pos = window->map->player.pos;
	const double		x_screen = (pos->x - player_pos.x
			+ MINIMAP_RADIUS) * scale + MINIMAP_XOFFSET;
	const double		y_screen = (pos->y - player_pos.y
			+ MINIMAP_RADIUS) * scale + MINIMAP_YOFFSET;
	t_pos				screen_pos;

	set_pos(&screen_pos, x_screen, y_screen);
	return (screen_pos);
}
