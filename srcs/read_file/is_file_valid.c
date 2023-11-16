/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechon <lechon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:05:03 by jrouillo          #+#    #+#             */
/*   Updated: 2023/11/01 11:16:48 by lechon           ###   ########.fr       */
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
	bool	is_valid;

	is_valid = true;
	if (is_file_readable(fd) == false)
	{
		print_format_error(strerror(errno));
		is_valid = false;
	}
	if (is_filename_valid(filename) == false)
	{
		print_format_error(INVALID_FILENAME);
		is_valid = false;
	}
	return (is_valid);
}
