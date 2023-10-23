/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 09:39:32 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/23 20:49:23 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_player(t_map *const map)
{
	map->player = get_player(map);
}

void	init_window(
	t_win *const window,
	t_map *const map,
	const t_config *const config
	)
{
	window->mlx_ptr = mlx_init();
	if (window->mlx_ptr == NULL)
	{
		print_format_error(MLX_ERROR);
		return ;
	}
	window->win_ptr = mlx_new_window(window->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	if (window->win_ptr == NULL)
	{
		print_format_error(MLX_ERROR);
		return ;
	}
	init_data(window->mlx_ptr, &window->data);
	init_player(map);
	window->map = map;
	window->config = config;
}
