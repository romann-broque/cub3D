/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 09:39:32 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/18 10:10:39 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_window(t_win *const window, t_map *const map)
{
	window->mlx_ptr = mlx_init();
	if (window->mlx_ptr == NULL)
	{
		print_format_error(strerror(errno));
		return ;
	}
	window->win_ptr = mlx_new_window(window->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	if (window->win_ptr == NULL)
	{
		print_format_error(strerror(errno));
		return ;
	}
	init_data(window->mlx_ptr, &window->data);
	window->map = map;
}
