/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:05:03 by jrouillo          #+#    #+#             */
/*   Updated: 2023/10/06 09:24:16 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_filename_valid(const char *const filename)
{
	return (is_suffix_valid(filename, FILE_EXTENSION));
}

static bool	is_file_readable(const int fd)
{
	return (fd != INVALID_FD);
}

bool	is_file_valid(const char *const filename, const int fd)
{
	return (is_filename_valid(filename) && is_file_readable(fd));
}
