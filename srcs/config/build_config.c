/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:44:49 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/14 18:33:47 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static ssize_t	build_attributes(
	t_config *const config,
	char *const *const lines)
{
	char	**sequence;
	int		attribute_status;
	ssize_t	offset;

	offset = 0;
	sequence = ft_split(lines[offset], SPACE);
	if (sequence == NULL)
		print_format_error(strerror(errno));
	attribute_status = build_attribute_from_sequence(config, sequence);
	while (offset != INVALID_OFFSET && attribute_status == EXIT_SUCCESS)
	{
		++offset;
		free_strs(sequence);
		sequence = ft_split(lines[offset], SPACE);
		if (sequence == NULL)
		{
			print_format_error(strerror(errno));
			offset = INVALID_OFFSET;
		}
		attribute_status = build_attribute_from_sequence(config, sequence);
	}
	offset = check_complete_config(offset, attribute_status, config);
	free_strs(sequence);
	return (offset);
}

static int	set_texture(
	t_texture *const texture,
	char *const texture_file,
	void *const mlx_ptr
	)
{
	if (texture_file == NULL)
		return (EXIT_SUCCESS);
	texture->data.img = mlx_xpm_file_to_image(mlx_ptr,
			texture_file, &texture->width, &texture->height);
	if (texture->data.img == NULL)
	{
		print_format_error(INVALID_TEXTURE);
		print_error(RED_PRINT"%s: %s\n"NC, strerror(errno), texture_file);
		return (EXIT_FAILURE);
	}
	texture->data.addr = mlx_get_data_addr(texture->data.img,
			&(texture->data.bits_per_pixel),
			&(texture->data.line_length), &(texture->data.endian));
	if (texture->data.addr == NULL)
	{
		print_format_error(MLX_ERROR);
		return (EXIT_FAILURE);
	}
	texture->data.byte_per_pixel = texture->data.bits_per_pixel / BITS_PER_BYTE;
	if (are_dimensions_valid(texture->height, texture->width) == false)
	{
		print_format_warning(DIMENSIONS_NOT_SUPPORTED);
		print_error(ORANGE_PRINT"(%s)\n"NC, texture_file);
	}
	return (EXIT_SUCCESS);
}

static int	set_textures_array(
	t_config *const config,
	void *const mlx_ptr
	)
{
	int		ret_val;
	size_t	i;
	size_t	j;

	ret_val = EXIT_SUCCESS;
	i = 0;
	while (i < TEXTURE_COUNT && ret_val == EXIT_SUCCESS)
	{
		j = 0;
		while (j < MAX_TEXTURE_COUNT && config->attribute_array[i][j] != NULL)
		{
			ret_val = set_texture(&(config->textures[i][j]),
					config->attribute_array[i][j], mlx_ptr);
			++j;
		}
		++i;
	}
	return (ret_val);
}

static void	set_dark_status(t_config *const config)
{
	if (BONUS)
	{
		config->is_dark
			= (config->attribute_array[E_DARK][0] != NULL
				&& streq(config->attribute_array[E_DARK][0], DARK_ON));
	}
	else
		config->is_dark = false;
}

ssize_t	build_config(
	t_config *const config,
	char *const *const lines,
	void *const mlx_ptr,
	void *const win_ptr
	)
{
	ssize_t	offset;

	init_config(config);
	if (mlx_ptr == NULL || win_ptr == NULL)
		return (INVALID_OFFSET);
	offset = build_attributes(config, lines);
	if (offset != INVALID_OFFSET)
	{
		if (BONUS == false)
			set_color(config);
		set_dark_status(config);
		if (set_textures_array(config, mlx_ptr) == EXIT_FAILURE)
			offset = INVALID_OFFSET;
	}
	return (offset);
}
