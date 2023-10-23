/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:11:15 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/23 14:40:40 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_tile_sequence(
	t_win *const window,
	const size_t sequence_index)
{
	size_t	i;
	t_pos	pos;

	i = 0;
	while (i < window->map->width)
	{
		set_pos(&pos, i, sequence_index);
		draw_tile(window, pos,
			i * (TILE_SIZE - 1) + MAP_XOFFSET,
			sequence_index * (TILE_SIZE - 1) + MAP_YOFFSET);
		++i;
	}
}

void	display_map(t_win *const window)
{
	size_t	i;

	i = 0;
	while (i < window->map->height)
	{
		draw_tile_sequence(window, i);
		++i;
	}
	display_player_on_map(window);
}
