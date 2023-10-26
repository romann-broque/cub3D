/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_window_complete.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:06:30 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/25 13:40:35 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_data_complete(const t_data *const data)
{
	return (data->img != NULL && data->addr != NULL);
}

bool	is_window_complete(t_win *const window)
{
	return (window != NULL
		&& window->mlx_ptr != NULL
		&& window->win_ptr != NULL
		&& window->map != NULL
		&& is_data_complete(&(window->data)) == true);
}
