/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_config_sequence_valid.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jess <jess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:25:37 by jess              #+#    #+#             */
/*   Updated: 2023/10/16 10:37:35 by jess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_attribute_key(const char *const key)
{
	size_t						i;
	static const char *const	attribute_key[] = {
		NORTH_KEY,
		SOUTH_KEY,
		WEST_KEY,
		EAST_KEY,
		FLOOR_KEY,
		CEIL_KEY
	};

	i = 0;
	while (i < ATTRIBUTE_COUNT && streq(key, attribute_key[i]) == false)
		i++;
	return (i < ATTRIBUTE_COUNT);
}

static bool	has_two_elements(char *const *const sequence)
{
	return (get_size_strs(sequence) == 2);
}

bool	is_sequence_valid(char *const *const sequence)
{
	return (has_two_elements(sequence) && is_attribute_key(sequence[0]));
}
