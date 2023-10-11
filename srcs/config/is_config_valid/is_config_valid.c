/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_config_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jess <jess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:03:54 by jess              #+#    #+#             */
/*   Updated: 2023/10/11 17:02:00 by jess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_config_complete(const t_config *const config)
{
	return (config != NULL
		&& config->north_texture != NULL && config->south_texture != NULL
		&& config->east_texture	&& config->west_texture != NULL
		&& config->floor_color != NULL && config->ceiling_color != NULL);
}
