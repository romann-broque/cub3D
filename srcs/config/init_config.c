/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:57:21 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/13 16:56:51 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_attributes(t_config *const config)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < ATTRIBUTE_COUNT)
	{
		j = 0;
		while (j < MAX_TEXTURE_COUNT)
		{
			config->attribute_array[i][j] = NULL;
			++j;
		}
		++i;
	}
}

static void	init_textures(t_config *const config)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < TEXTURE_COUNT)
	{
		j = 0;
		while (j < MAX_TEXTURE_COUNT)
		{
			config->textures[i][j].data.img = NULL;
			++j;
		}
		++i;
	}
}

void	init_config(t_config *const config)
{
	init_attributes(config);
	init_textures(config);
}
