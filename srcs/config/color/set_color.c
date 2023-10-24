/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:21:13 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/23 16:22:53 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_color(t_config *const config)
{
	config->ceil_color = get_color_from_rgb(config->attribute_array[E_CEIL]);
	config->floor_color = get_color_from_rgb(config->attribute_array[E_FLOOR]);
}
