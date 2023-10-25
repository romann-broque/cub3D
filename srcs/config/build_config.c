/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechon <lechon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:44:49 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/25 18:17:48 by lechon           ###   ########.fr       */
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

static int	set_texture(
	t_texture *const texture,
	char *const texture_file,
	void *const mlx_ptr,
	t_data *const data
	)
{
	int			height;
	int			width;
	void *const	img = mlx_xpm_file_to_image(mlx_ptr,
			texture_file, &width, &height);

	if (img == NULL)
	{
		print_format_error(INVALID_TEXTURE);
		print_error(RED_PRINT"%s: %s\n"NC, strerror(errno), texture_file);
		return (EXIT_FAILURE);
	}
	texture->content = mlx_get_data_addr(img,
			&(data->bits_per_pixel), &(data->line_length), &(data->endian));
	texture->height = height;
	texture->width = width;
	return (EXIT_SUCCESS);
}

static int	set_textures_array(
	t_config *const config,
	void *const mlx_ptr,
	t_data *const data
	)
{
	int		ret_val;
	size_t	i;

	ret_val = EXIT_SUCCESS;
	i = 0;
	while (i < TEXTURE_COUNT && ret_val == EXIT_SUCCESS)
	{
		ret_val = set_texture(config->textures + i,
				config->attribute_array[i], mlx_ptr, data);
		++i;
	}
	return (ret_val);
}

ssize_t	build_config(
	t_config *const config,
	char *const *const lines,
	void *const mlx_ptr,
	t_data *const data
	)
{
	ssize_t	offset;

	init_config(config);
	if (mlx_ptr == NULL)
		return (INVALID_OFFSET);
	offset = build_attributes(config, lines);
	if (offset != INVALID_OFFSET)
	{
		set_color(config);
		if (set_textures_array(config, mlx_ptr, data) == EXIT_FAILURE)
			offset = INVALID_OFFSET;
	}
	return (offset);
}
