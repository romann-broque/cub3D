/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jess <jess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:28:07 by jess              #+#    #+#             */
/*   Updated: 2023/10/12 10:33:11 by jess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_config	*init_config(char *const *const content)
{
	char 				**sequence;
	t_config 			*config;
	size_t				i;

	if (content == NULL)
		return (NULL);
	config = NULL;
	i = 0;
	while (content[i] != NULL && is_config_complete(config) == false)
	{
		sequence = ft_split(content[i], BLANK);
		if (is_sequence_valid(sequence) == false)
		{
			free_config(config);
			break ;
		}
		// else if (sequence[i] != NULL)
		// {
		// 	key = get_key_from_sequence(sequence);
		// 	value = get_value_from_sequence(sequence);
		// 	add_to_config(config, key, value);
		// }
		free_strs(sequence);
		i++;
	}
	return (config);
}
