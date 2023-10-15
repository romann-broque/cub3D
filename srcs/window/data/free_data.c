/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 09:56:17 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/15 10:02:17 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_data(const t_data *data, void *const mlx_ptr)
{
	if (mlx_ptr != NULL && data->img != NULL)
		mlx_destroy_image(mlx_ptr, data->img);
}
