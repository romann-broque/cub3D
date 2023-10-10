/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_from_file.test.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:55:42 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/10 08:31:15 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cunit.test.h"

t_map	*get_map_from_file(const char *const filename)
{
	char **const	content = get_file(filename);
	t_map			*map;

	if (content == NULL)
		return (NULL);
	map = init_map(content);
	free_strs(content);
	return (map);
}
