/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 09:57:38 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/25 13:41:55 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_window(t_win *const window)
{
	if (window != NULL)
	{
		if (window->mlx_ptr != NULL)
		{
			if (window->win_ptr != NULL)
			{
				free_data(&window->data, window->mlx_ptr);
				mlx_destroy_window(window->mlx_ptr, window->win_ptr);
			}
			mlx_destroy_display(window->mlx_ptr);
		}
		free(window->mlx_ptr);
		free_config(&(window->config));
		free_map(window->map);
	}
}
