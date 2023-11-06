/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_mark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 07:25:03 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/06 07:25:31 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_marked(
	const t_map *const map,
	const size_t x,
	const size_t y
	)
{
	return (map->matrix[y][x].is_marked == true);
}

void	mark_as_viewed(
	const t_map *const map,
	const size_t x,
	const size_t y
	)
{
	map->matrix[y][x].is_marked = true;
}
