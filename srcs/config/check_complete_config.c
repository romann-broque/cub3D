/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_complete_config.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:50:14 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/14 18:06:28 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

ssize_t	check_complete_config(
	ssize_t offset,
	const int attribute_status,
	const t_config *const config
)
{
	if (attribute_status == ATTRIBUTE_DUPLICATED
		|| attribute_status == ATTRIBUTE_VALUE_FAILURE)
		offset = INVALID_OFFSET;
	else if (offset != INVALID_OFFSET
		&& is_config_complete(config) == false)
	{
		print_format_error(UNKNOWN_CONFIG);
		offset = INVALID_OFFSET;
	}
	return (offset);
}
