/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:05:03 by jrouillo          #+#    #+#             */
/*   Updated: 2023/10/06 11:08:56 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_suffix_valid(const char *const str, const char *const suffix)
{
	const size_t	len_str = ft_strlen(str);
	const size_t	len_suffix = ft_strlen(suffix);
	size_t			offset;

	if (len_str < len_suffix)
		return (false);
	offset = len_str - len_suffix;
	return (streq(str + offset, suffix));
}

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
