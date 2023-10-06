/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:00:52 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/06 16:16:57 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_matrix(char *const*const matrix, const size_t height)
{
	size_t	i;

	i = 0;
	while (i < height)
	{
		printf("%s\n", matrix[i]);
		++i;
	}
}

void	print_map(const t_map *const map)
{
	if (map != NULL)
	{
		printf("Height: %zu\nWidth: %zu\n\n", map->height, map->width);
		print_matrix(map->matrix, map->height);
	}
}
