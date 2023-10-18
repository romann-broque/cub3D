/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:44:49 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/12 08:34:58 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_config_complete(const t_config *const config)
{
	size_t	i;

	i = 0;
	while (config->attribute_array[i] != NULL)
		++i;
	return (i == ATTRIBUTE_COUNT);
}

ssize_t	build_config(t_config *const config, char *const *const lines)
{
	char	**sequence;
	ssize_t	offset;

	offset = 0;
	while (offset != INVALID_OFFSET && is_config_complete(config) == false)
	{
		sequence = ft_split(lines[offset], SPACE);
		if (sequence == NULL
			|| build_attribute_from_sequence(config, sequence) == EXIT_FAILURE)
		{
			if (sequence == NULL)
				print_format_error(strerror(errno));
			offset = INVALID_OFFSET;
		}
		else
			++offset;
		free_strs(sequence);
	}
	return (offset);
}
