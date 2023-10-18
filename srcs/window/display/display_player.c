/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 07:44:26 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/18 14:17:23 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display_player(t_win *const window)
{
	const t_pos	player_pos = window->map->player_pos;

	put_pixel(&(window->data),
		(MINIMAP_XOFFSET + player_pos.x) * (TILE_SIZE - 1),
		(MINIMAP_YOFFSET + player_pos.y) * (TILE_SIZE - 1),
		GREEN);
}
