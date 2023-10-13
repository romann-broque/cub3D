/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 07:29:33 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/12 07:32:40 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_attribute_array(char *attribute_array[ATTRIBUTE_COUNT + 1])
{
	size_t	i;

	i = 0;
	while (i < ATTRIBUTE_COUNT)
	{
		free(attribute_array[i]);
		++i;
	}
}

void	free_config(t_config *const config)
{
	free_attribute_array(config->attribute_array);
}
