/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:57:21 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/27 06:55:11 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_attributes(t_config *const config)
{
	size_t	i;

	i = 0;
	while (i < ATTRIBUTE_COUNT)
	{
		config->attribute_array[i] = NULL;
		++i;
	}
	config->attribute_array[i] = NULL;
}

static void	init_textures(t_config *const config)
{
	size_t	i;

	i = 0;
	while (i < TEXTURE_COUNT)
	{
		config->textures[i].data.img = NULL;
		++i;
	}
}

void	init_config(t_config *const config)
{
	init_attributes(config);
	init_textures(config);
}
