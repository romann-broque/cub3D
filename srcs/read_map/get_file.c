/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:13:34 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/06 11:46:29 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*get_file_content(const int fd)
{
	char	*line;
	char	*file_content;

	file_content = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		file_content = ft_strjoin_free(file_content, line);
		free(line);
		line = get_next_line(fd);
	}
	return (file_content);
}

char	*get_file(const char *const filename)
{
	const int	fd = open(filename, O_RDONLY);
	char		*file_content;

	file_content = NULL;
	if (is_file_valid(filename, fd) == true)
		file_content = get_file_content(fd);
	else if (fd != INVALID_FD)
		close(fd);
	return (file_content);
}
