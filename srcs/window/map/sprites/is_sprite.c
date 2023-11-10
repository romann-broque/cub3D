/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:05:37 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/09 13:06:20 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_sprite(const t_map *const map, const size_t x, const size_t y)
{
	return (is_in_str(SPRITES, map->matrix[y][x].tile_char));
}
