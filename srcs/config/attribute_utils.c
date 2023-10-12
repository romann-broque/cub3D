/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attribute_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 07:57:46 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/12 09:57:38 by rbroque          ###   ########.fr       */
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

static int	add_attribute_into_config(
	t_config *const config,
	char *const *const sequence
	)
{
	static const char			*attribute_name_array[] = {
		NORTH_NAME,
		SOUTH_NAME,
		WEST_NAME,
		EAST_NAME,
		FLOOR_NAME,
		CEIL_NAME,
		NULL
	};
	const char					*attribute_name = sequence[0];
	const char					*value = sequence[1];
	const enum e_attribute_type	type
		= find_attribute_type(attribute_name_array, attribute_name);
	int							ret_val;

	ret_val = EXIT_FAILURE;
	if (config->attribute_array[type] == NULL)
	{
		config->attribute_array[type] = ft_strdup(value);
		ret_val = EXIT_SUCCESS;
	}
	if (config->attribute_array[type] == NULL)
		print_format_error(strerror(errno));
	return (ret_val);
}

/*
	--> build_attribute_from_sequence must return this

	return !((is_sequence_valid(sequence) == true
			&& (is_sequence_empty(sequence) == true
			|| add_attribute_into_config(config, sequence) == EXIT_SUCCESS))))

*/

int	build_attribute_from_sequence(
	t_config *const config,
	char *const *const sequence
	)
{
	if (get_size_strs(sequence) == 2
		&& add_attribute_into_config(config, sequence) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	if (is_sequence_empty(sequence) == true)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
