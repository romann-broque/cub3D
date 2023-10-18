/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 07:44:26 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/18 10:03:46 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display_player(t_win *const window)
{
	const t_pos	player_pos = window->map->player_pos;

	put_pixel(&(window->data),
		(MINIMAP_RADIUS + MINIMAP_XOFFSET) * (TILE_SIZE - 1) + player_pos.x,
		(MINIMAP_RADIUS + MINIMAP_YOFFSET) * (TILE_SIZE - 1) + player_pos.y,
		GREEN);
}
