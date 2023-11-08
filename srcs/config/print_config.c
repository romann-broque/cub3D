/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:44:51 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/03 14:59:06 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_config(t_config *const config)
{
	printf("Config:\n\n");
	printf("north_texture: %s\n", config->attribute_array[E_NORTH]);
	printf("south_texture: %s\n", config->attribute_array[E_SOUTH]);
	printf("west_texture: %s\n", config->attribute_array[E_WEST]);
	printf("east_texture: %s\n", config->attribute_array[E_EAST]);
	printf("floor: %s\n", config->attribute_array[E_FLOOR]);
	printf("ceil: %s\n", config->attribute_array[E_CEIL]);
	if (config->attribute_array[E_DOOR])
		printf("door: %s\n", config->attribute_array[E_DOOR]);
	else
		printf("door texture not set\n");
}
