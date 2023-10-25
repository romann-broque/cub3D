/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:44:49 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/25 13:49:57 by rbroque          ###   ########.fr       */
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

static ssize_t	build_attributes(
	t_config *const config,
	char *const *const lines)
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
/*
// static int	set_texture(
// 	t_texture *const texture,
// 	const char *const texture_file)
// {
// 	texture->content = mlx_xpm_file_to_image();

// }

// static int	set_textures_array(t_config *const config)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < TEXTURE_COUNT)
// 	{
// 		set_texture(config->textures + i, config->attribute_array[i]);
// 		++i;
// 	}
// }
		// if (set_textures_array(config) == EXIT_FAILURE)
		// 	offset = INVALID_OFFSET;
*/

ssize_t	build_config(t_config *const config, char *const *const lines)
{
	ssize_t	offset;

	init_config(config);
	offset = build_attributes(config, lines);
	if (offset != INVALID_OFFSET)
	{
		set_color(config);
	}
	return (offset);
}
