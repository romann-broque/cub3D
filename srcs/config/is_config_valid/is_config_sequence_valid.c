/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_config_sequence_valid.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jess <jess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:25:37 by jess              #+#    #+#             */
/*   Updated: 2023/10/12 11:55:12 by jess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_attribute_key(const char *const key)
{
	size_t						i;
	static const char *const	attribute_name[] = {
		NORTH,
		SOUTH,
		WEST,
		EAST,
		FLOOR,
		CEIL
	};

	while (i < ATTRIBUTE_COUNT)
	{
		if (streq(key, attribute_name[i]) == true)
			return (true);
		i++;
	}
	return (false);
}

static bool	has_two_elements(char *const *const sequence)
{
	return (get_size_strs(sequence) >= 2);
}

bool	is_sequence_valid(char *const *const sequence)
{
	return (has_two_elements(sequence) && is_attribute_key(sequence[0]));
}
