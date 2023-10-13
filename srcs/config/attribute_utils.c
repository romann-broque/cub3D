/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attribute_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 07:57:46 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/13 09:16:48 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_sequence_empty(char *const *const sequence)
{
	return (get_size_strs(sequence) == 0);
}

static enum e_attribute_type	find_attribute_type(
	const char *attribute_KEY_array[ATTRIBUTE_COUNT + 1],
	const char *name
	)
{
	enum e_attribute_type	type;

	type = 0;
	while (type < ATTRIBUTE_COUNT
		&& streq(attribute_KEY_array[type], name) == false)
		++type;
	return (type);
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
	if (type < ATTRIBUTE_COUNT)
		print_format_error(UNKNOWN_CONFIG);
	else if (config->attribute_array[type] == NULL)
		print_format_error(DUPLICATED_CONFIG);
	else
	{
		config->attribute_array[type] = ft_strdup(value);
		if (config->attribute_array[type] == NULL)
			print_format_error(strerror(errno));
		else
			ret_val = EXIT_SUCCESS;
	}
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
	if (is_sequence_empty(sequence) == true)
		return (EXIT_SUCCESS);
	if (get_size_strs(sequence) == 2
		&& add_attribute_into_config(
			config, sequence[0], sequence[1]) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
