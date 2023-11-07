/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechon <lechon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:13:34 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/01 11:16:31 by lechon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	rm_newline(char *const str)
{
	const size_t	len = ft_strlen(str);

	if (len > 0 && str[len - 1] == NEWLINE)
		str[len - 1] = END_CHAR;
}

static size_t	count_lines(const int fd)
{
	size_t	count;
	char	*line;

	count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		++count;
	}
	return (count);
}

static ssize_t	get_line_count(const char *const filename)
{
	const int	fd = open(filename, O_RDONLY);
	ssize_t		count;

	count = COUNT_LINE_ERROR;
	if (is_file_valid(filename, fd) == true)
		count = count_lines(fd);
	if (fd != INVALID_FD)
		close(fd);
	return (count);
}

static char	**get_file_content(const int fd, const size_t line_count)
{
	char **const	lines = malloc((line_count + 1) * sizeof(char *));
	size_t			i;

	if (lines == NULL)
	{
		print_format_error(strerror(errno));
		return (NULL);
	}
	i = 0;
	while (i < line_count)
	{
		lines[i] = get_next_line(fd);
		if (lines[i] == NULL)
		{
			print_format_error(strerror(errno));
			free_strs(lines);
			return (NULL);
		}
		rm_newline(lines[i]);
		++i;
	}
	lines[i] = NULL;
	return (lines);
}

char	**get_file(const char *const filename)
{
	const ssize_t	line_count = get_line_count(filename);
	int				fd;
	char			**file_content;

	if (line_count == COUNT_LINE_ERROR)
		return (NULL);
	file_content = NULL;
	fd = open(filename, O_RDONLY);
	if (is_file_valid(filename, fd) == true)
		file_content = get_file_content(fd, line_count);
	if (fd != INVALID_FD)
		close(fd);
	return (file_content);
}
