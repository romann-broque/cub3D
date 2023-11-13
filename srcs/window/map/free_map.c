/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:23:35 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/13 17:13:41 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_tile_matrix(t_tile **const matrix, const size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(matrix[i]);
		++i;
	}
	free(matrix);
}

void	free_map(t_map *const map)
{
	if (map != NULL && map->matrix != NULL)
	{
		if (map->matrix != NULL)
			free_tile_matrix(map->matrix, map->height);
		if (map->sprite_array != NULL)
			free(map->sprite_array);
	}
	free(map);
}
