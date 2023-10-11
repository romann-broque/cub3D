/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jess <jess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:58:39 by jess              #+#    #+#             */
/*   Updated: 2023/10/11 17:01:27 by jess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_attributes(t_attribute *const attribute)
{
	free(attribute->key);
	free(attribute->value);
}

void	free_config(t_config *const config)
{
	if (config != NULL)
	{
		free_attributes(config->north_texture);
		free_attributes(config->south_texture);
		free_attributes(config->west_texture);
		free_attributes(config->east_texture);
	}
	free(config);
}
