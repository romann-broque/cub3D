/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_access.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:05:03 by jrouillo          #+#    #+#             */
/*   Updated: 2023/10/05 14:22:44 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_name_format_valid(const char *const filename)
{
	size_t	i;

	i = 0;
	while (filename[i])
		i++;
	if (filename[i - 1] != 'b' || filename[i - 2] != 'u'
		|| filename[i - 3] != 'c' || filename[i - 4] != '.')
		return (false);
	return (true);
}

static bool	are_permission_granted(const char *const filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (false);
	}
	close(fd);
	return (true);
}

bool	read_map_access(const char *const filename)
{
	if (are_permission_granted(filename) == false
		|| is_name_fromat_valid(filename) == false)
		return (false);
	return (true);
}
