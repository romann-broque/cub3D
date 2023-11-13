/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:53:28 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/13 15:53:40 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	refresh_sprites(t_map *const map)
{
	size_t	i;

	i = 0;
	while (i < map->sprite_count)
	{
		map->sprite_array[i].is_viewed = false;
		++i;
	}
}
