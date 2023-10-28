/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 08:09:03 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/28 22:56:45 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	refresh(t_win *window)
{
	mlx_clear_window(window->mlx_ptr, window->win_ptr);
	display_window_content(window);
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
		window->data.img, 0, 0);
}
