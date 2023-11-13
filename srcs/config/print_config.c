/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:44:51 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/10 07:48:40 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_attribute(
	const char *const name,
	const char *const attribute,
	const t_texture *const texture
	)
{
	if (attribute != NULL)
		printf("%s: %s (%p)\n", name, attribute, texture);
	else
		printf("%s texture not set\n", name);
}

static void	print_sprites(t_config *const config)
{
	size_t	i;

	i = E_SP1;
	while (i <= E_SP8)
	{
		print_attribute("sprite",
			config->attribute_array[i], &config->textures[i]);
		++i;
	}
}

void	print_config(t_config *const config)
{
	printf("Config:\n\n");
	print_attribute("north_texture",
		config->attribute_array[E_NORTH], &config->textures[E_NORTH]);
	print_attribute("south_texture",
		config->attribute_array[E_SOUTH], &config->textures[E_SOUTH]);
	print_attribute("west_texture",
		config->attribute_array[E_WEST], &config->textures[E_WEST]);
	print_attribute("east_texture",
		config->attribute_array[E_EAST], &config->textures[E_EAST]);
	print_attribute("ceil_texture",
		config->attribute_array[E_CEIL], &config->textures[E_CEIL]);
	print_attribute("floor_texture",
		config->attribute_array[E_FLOOR], &config->textures[E_FLOOR]);
	if (BONUS)
	{
		print_attribute("door",
			config->attribute_array[E_DOOR], &config->textures[E_DOOR]);
		print_sprites(config);
	}
}
