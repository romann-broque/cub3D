/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 08:51:46 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/17 14:20:55 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_ground(
	const t_map *const map,
	const size_t x,
	const size_t y
	)
{
	return (is_in_str(GROUND, map->matrix[y][x].tile_char));
}

bool	is_wall(
	const t_map *const map,
	const size_t x,
	const size_t y
	)
{
	return (map->matrix[y][x].tile_char == WALL);
}

bool	is_blank(
	const t_map *const map,
	const size_t x,
	const size_t y
	)
{
	return (map->matrix[y][x].tile_char == BLANK);
}
