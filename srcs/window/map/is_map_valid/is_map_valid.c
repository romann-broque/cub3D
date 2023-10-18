/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:43:14 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/09 20:57:17 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_map_valid(t_map *const map)
{
	bool	is_valid;

	is_valid = false;
	if (is_map_content_valid(map) == false)
		print_format_error(MAP_CONTENT_WRONG);
	else if (is_map_unique(map) == false)
		print_format_error(MAP_NOT_UNIQUE);
	else if (is_map_closed(map) == false)
		print_format_error(MAP_NOT_CLOSED);
	else
		is_valid = true;
	return (is_valid);
}
