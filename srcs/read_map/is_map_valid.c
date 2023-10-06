/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:33:53 by jrouillo          #+#    #+#             */
/*   Updated: 2023/10/06 14:35:41 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Contient uniquement un set de caractères (0, 1, ' ' et un unique(N, W, E, S))

static bool	is_unique_direction(char *const content)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (content[i] != '\0')
	{
		if (ft_strchr(VALID_CHAR_DIR, content[i]) != NULL)
			count++;
		i++;
	}
	if (count == 1)
		return (true);
	return (false);
}

static bool	is_character_valid(char *const content)
{
	size_t	i;

	i = 0;
	while (content[i] != '\0')
	{
		if (ft_strchr(VALID_CHAR, content[i]) == NULL)
			return (false);
		i++;
	}
	return (true);
}

bool	are_characters_valid(char *const content)
{
	return (is_character_valid(content) && is_unique_direction(content));
}
