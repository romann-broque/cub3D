/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:44:51 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/09 09:52:59 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_attribute(const char *const name, const char *const attribute)
{
	if (attribute != NULL)
		printf("%s: %s\n", name, attribute);
	else
		printf("%s texture not set\n", name);
}

void	print_config(t_config *const config)
{
	printf("Config:\n\n");
	print_attribute("north_texture", config->attribute_array[E_NORTH]);
	print_attribute("south_texture", config->attribute_array[E_SOUTH]);
	print_attribute("west_texture", config->attribute_array[E_WEST]);
	print_attribute("east_texture", config->attribute_array[E_EAST]);
	print_attribute("ceil_texture", config->attribute_array[E_CEIL]);
	print_attribute("floor_texture", config->attribute_array[E_FLOOR]);
	if (BONUS)
	{
		print_attribute("door", config->attribute_array[E_DOOR]);
		print_attribute("sprite1", config->attribute_array[E_SP1]);
		print_attribute("sprite2", config->attribute_array[E_SP2]);
		print_attribute("sprite3", config->attribute_array[E_SP3]);
		print_attribute("sprite4", config->attribute_array[E_SP4]);
		print_attribute("sprite5", config->attribute_array[E_SP5]);
		print_attribute("sprite6", config->attribute_array[E_SP6]);
		print_attribute("sprite7", config->attribute_array[E_SP7]);
		print_attribute("sprite8", config->attribute_array[E_SP8]);
	}
}
