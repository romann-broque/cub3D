/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attribute_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 07:57:46 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/09 09:09:11 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_config_complete(const t_config *const config)
{
	size_t	i;

	i = 0;
	while (config->attribute_array[i] != NULL)
		++i;
	return (i >= MANDATORY_ATTRIBUTE_COUNT);
}

static enum e_attribute_type	find_attribute_type(
	const char *name
	)
{
	static const char			*attribute_name_array[] = {
		NORTH_KEY, SOUTH_KEY,
		WEST_KEY, EAST_KEY,
		FLOOR_KEY, CEIL_KEY,
		DOOR_KEY, SP1_KEY,
		SP2_KEY, SP3_KEY,
		SP4_KEY, SP5_KEY,
		SP6_KEY, SP7_KEY,
		SP8_KEY, NULL
	};
	enum e_attribute_type		type;

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
	if ((type == E_CEIL || type == E_FLOOR)
		&& BONUS == false && is_rgb(str) == false)
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
	const enum e_attribute_type	type
		= find_attribute_type(name);
	int							ret_val;

	ret_val = ATTRIBUTE_FAILURE;
	if (config->attribute_array[type] != NULL)
	{
		print_format_error(DUPLICATED_CONFIG);
		ret_val = ATTRIBUTE_DUPLICATED;
	}
	else
	{
		assign_attribute(config, type, value);
		if (config->attribute_array[type] != NULL)
			ret_val = ATTRIBUTE_SUCCESS;
	}
	return (ret_val);
}

int	build_attribute_from_sequence(
	t_config *const config,
	char *const *const sequence
	)
{
	if (sequence == NULL)
		return (EXIT_FAILURE);
	if (is_sequence_empty(sequence) == true)
		return (EXIT_SUCCESS);
	if (is_sequence_format_valid(sequence) == false)
		return (EXIT_FAILURE);
	return (add_attribute_into_config(
			config, sequence[0], sequence[1]));
}
