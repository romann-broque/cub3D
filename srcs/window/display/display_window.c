/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:09:13 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/16 07:18:49 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_data_complete(const t_data *const data)
{
	return (data->img != NULL && data->addr != NULL);
}

static bool	is_window_complete(t_win *const window)
{
	return (window != NULL
		&& window->mlx_ptr != NULL
		&& window->win_ptr != NULL
		&& is_data_complete(&(window->data)) == true);
}

void	display_window(void)
{
	t_win	window;

	init_window(&window);
	if (is_window_complete(&window) == true)
		loop(&window);
	free_window(&window);
}
