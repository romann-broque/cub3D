/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 08:09:03 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/30 08:58:36 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	refresh(t_win *window)
{
	mlx_destroy_image(window->mlx_ptr, window->data.img);
	init_data(window->mlx_ptr, &(window->data));
	if (window->data.img == NULL)
	{
		print_format_error(MLX_ERROR);
		return (EXIT_FAILURE);
	}
	display_window_content(window);
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
		window->data.img, 0, 0);
	return (EXIT_SUCCESS);
}
