/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attribute_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 07:57:46 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/14 11:12:25 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_config_complete(const t_config *const config)
{
	size_t	i;

	i = 0;
	while (i < MANDATORY_ATTRIBUTE_COUNT
		&& config->attribute_array[i][0] != NULL)
		++i;
	return (i >= MANDATORY_ATTRIBUTE_COUNT);
}

enum e_attribute_type	find_attribute_type(
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
		SP8_KEY, DARK_KEY,
		NULL
	};
	enum e_attribute_type		type;

	type = 0;
	while (type < ATTRIBUTE_COUNT
		&& streq(attribute_name_array[type], name) == false)
		++type;
	return (type);
}

bool	is_valid_dark_value(const char *const value)
{
	return (streq(value, DARK_ON) || streq(value, DARK_OFF));
}

int	fill_attribute(
	t_config *const config,
	const enum e_attribute_type type,
	char *const *const values
)
{
	size_t	i;

	i = 0;
	while (i < MAX_TEXTURE_COUNT && values[i] != NULL)
	{
		config->attribute_array[type][i] = ft_strdup(values[i]);
		if (config->attribute_array[type][i] == NULL)
		{
			print_format_error(strerror(errno));
			return (EXIT_FAILURE);
		}
		++i;
	}
	if (i == MAX_TEXTURE_COUNT && values[i] != NULL)
		print_format_warning(TOO_MANY_TEXTURES);
	return (EXIT_SUCCESS);
}
