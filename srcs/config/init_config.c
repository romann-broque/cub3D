/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:57:21 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/12 07:20:18 by rbroque          ###   ########.fr       */
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

void	init_config(t_config *const config)
{
	init_attributes(config);
}
