/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:44:51 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/14 10:46:15 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_attribute(
	const char *const name,
	char *const *const values
	)
{
	size_t	i;

	if (values != NULL)
	{
		i = 0;
		printf("%s: ", name);
		while (i < MAX_TEXTURE_COUNT && values[i] != NULL)
		{
			printf("%s ", values[i]);
			++i;
		}
		printf("\n");
	}
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
			config->attribute_array[i]);
		++i;
	}
}

void	print_config(t_config *const config)
{
	printf("Config:\n\n");
	print_attribute("north_texture",
		config->attribute_array[E_NORTH]);
	print_attribute("south_texture",
		config->attribute_array[E_SOUTH]);
	print_attribute("west_texture",
		config->attribute_array[E_WEST]);
	print_attribute("east_texture",
		config->attribute_array[E_EAST]);
	print_attribute("ceil_texture",
		config->attribute_array[E_CEIL]);
	print_attribute("floor_texture",
		config->attribute_array[E_FLOOR]);
	if (BONUS)
	{
		print_attribute("door",
			config->attribute_array[E_DOOR]);
		print_sprites(config);
		print_attribute("DARK",
			config->attribute_array[E_DARK]);
	}
}
