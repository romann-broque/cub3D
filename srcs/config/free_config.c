/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 07:29:33 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/13 17:06:09 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_attribute_array(
	char *attribute_array[ATTRIBUTE_COUNT + 1][MAX_TEXTURE_COUNT]
)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < ATTRIBUTE_COUNT)
	{
		j = 0;
		while (j < MAX_TEXTURE_COUNT && attribute_array[i][j] != NULL)
		{
			free(attribute_array[i][j]);
			++j;
		}
		++i;
	}
}

static void	destroy_textures(
	t_texture textures[TEXTURE_COUNT][MAX_TEXTURE_COUNT],
	void *const mlx_ptr
	)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < TEXTURE_COUNT)
	{
		j = 0;
		while (j < MAX_TEXTURE_COUNT)
		{
			free_data(&(textures[i][j].data), mlx_ptr);
			++j;
		}
		++i;
	}
}

void	free_config(t_config *const config, void *const mlx_ptr)
{
	free_attribute_array(config->attribute_array);
	destroy_textures(config->textures, mlx_ptr);
}
