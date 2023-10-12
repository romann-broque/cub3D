/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_config_sequence_valid.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jess <jess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:25:37 by jess              #+#    #+#             */
/*   Updated: 2023/10/12 10:34:33 by jess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_attribute_key(char **sequence)
{
	size_t	i;

	i = 0;
	if (sequence[0] != NULL)
	{
			if (ft_strncmp(sequence[0], NORTH, ft_strlen(sequence[0])) == 0
				|| ft_strncmp(sequence[0], SOUTH, ft_strlen(sequence[0])) == 0
				|| ft_strncmp(sequence[0], WEST, ft_strlen(sequence[0])) == 0
				|| ft_strncmp(sequence[0], EAST, ft_strlen(sequence[0])) == 0)
				return (true);
			i++;
	}
	return (false);
}

static bool	has_two_elements(char **sequence)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (sequence[i] != NULL)
	{
		count += 1;
		i++;
	}
	return (count == 2);
}

bool	is_sequence_valid(char **sequence)
{
	return (has_two_elements(sequence) && is_attribute_key(sequence));
}
