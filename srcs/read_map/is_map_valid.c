/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:33:53 by jrouillo          #+#    #+#             */
/*   Updated: 2023/10/09 10:35:19 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_unique_direction(const char *const content)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (VALID_CHAR_DIR[i] != '\0')
	{
		count += count_c_in_str(content, VALID_CHAR_DIR[i]);
		i++;
	}
	if (count == 1)
		return (true);
	return (false);
}

static bool	is_charset_valid(const char *const content)
{
	size_t	i;

	i = 0;
	while (content[i] != '\0')
	{
		if (is_in_str(VALID_CHAR, content[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

bool	are_characters_valid(const char *const content)
{
	return (is_charset_valid(content) && is_unique_direction(content));
}
