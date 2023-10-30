/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:44:51 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/28 15:45:05 by rbroque          ###   ########.fr       */
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
}
