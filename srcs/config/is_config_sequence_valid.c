/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_config_sequence_valid.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:25:37 by jess              #+#    #+#             */
/*   Updated: 2023/11/05 11:01:14 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_attribute_key(const char *const key)
{
	size_t						i;
	size_t						limit;
	static const char *const	attribute_key[] = {
		NORTH_KEY,
		SOUTH_KEY,
		WEST_KEY,
		EAST_KEY,
		FLOOR_KEY,
		CEIL_KEY,
		DOOR_KEY
	};

	i = 0;
	limit = MANDATORY_ATTRIBUTE_COUNT;
	if (BONUS)
		limit = ATTRIBUTE_COUNT;
	while (i < limit && streq(key, attribute_key[i]) == false)
		i++;
	return (i < limit);
}

static bool	has_two_elements(char *const *const sequence)
{
	return (get_size_strs(sequence) == 2);
}

bool	is_sequence_empty(char *const *const sequence)
{
	return (get_size_strs(sequence) == 0);
}

bool	is_sequence_format_valid(char *const *const sequence)
{
	return (has_two_elements(sequence) && is_attribute_key(sequence[0]));
}

bool	is_sequence_valid(char *const *const sequence)
{
	return (sequence != NULL && (is_sequence_empty(sequence)
			|| is_sequence_format_valid(sequence)));
}
