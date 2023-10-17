/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:11:15 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/17 09:05:27 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display_map(t_win *const window)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < window->map->height)
	{
		j = 0;
		while (j < window->map->width)
		{
			draw_tile(window, j, i);
			++j;
		}
		++i;
	}
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
		window->data.img, 0, 0);
}
