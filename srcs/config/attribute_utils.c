/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attribute_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 07:57:46 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/25 14:47:46 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_sequence_empty(char *const *const sequence)
{
	return (get_size_strs(sequence) == 0);
}

static enum e_attribute_type	find_attribute_type(
	const char *attribute_name_array[ATTRIBUTE_COUNT + 1],
	const char *name
	)
{
	enum e_attribute_type	type;

	type = 0;
	while (type < ATTRIBUTE_COUNT
		&& streq(attribute_name_array[type], name) == false)
		++type;
	return (type);
}

void	assign_attribute(
	t_config *const config,
	const enum e_attribute_type type,
	const char *const str
	)
{
	if ((type == E_CEIL || type == E_FLOOR) && is_rgb(str) == false)
		print_format_error(WRONG_RGB);
	else
	{
		config->attribute_array[type] = ft_strdup(str);
		if (config->attribute_array[type] == NULL)
			print_format_error(strerror(errno));
	}
}

static int	add_attribute_into_config(
	t_config *const config,
	const char *const name,
	const char *const value
	)
{
	static const char			*attribute_name_array[] = {
		NORTH_KEY, SOUTH_KEY,
		WEST_KEY, EAST_KEY,
		FLOOR_KEY, CEIL_KEY,
		NULL
	};
	const enum e_attribute_type	type
		= find_attribute_type(attribute_name_array, name);
	int							ret_val;

	ret_val = EXIT_FAILURE;
	if (config->attribute_array[type] != NULL)
		print_format_error(DUPLICATED_CONFIG);
	else
	{
		assign_attribute(config, type, value);
		if (config->attribute_array[type] != NULL)
			ret_val = EXIT_SUCCESS;
	}
	return (ret_val);
}

int	build_attribute_from_sequence(
	t_config *const config,
	char *const *const sequence
	)
{
	if (is_sequence_empty(sequence) == true)
		return (EXIT_SUCCESS);
	if (is_sequence_valid(sequence) == false)
	{
		print_format_error(UNKNOWN_CONFIG);
		return (EXIT_FAILURE);
	}
	if (add_attribute_into_config(
			config, sequence[0], sequence[1]) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
