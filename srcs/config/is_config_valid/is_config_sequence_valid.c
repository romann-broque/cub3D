/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_config_sequence_valid.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jess <jess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:25:37 by jess              #+#    #+#             */
/*   Updated: 2023/10/13 12:15:21 by jess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Dans attribute_utils.c, dans la fonction add_attribute_to_config, retirer
	la partie où on check si ça fait partie des keys ou pas
	if (type < ATTRIBUTE_COUNT)
		print_format_error(UNKNOWN_CONFIG);
	+ rajouter is_sequence_empty
*/

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
