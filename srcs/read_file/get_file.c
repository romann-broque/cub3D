/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:13:34 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/10 12:29:11 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_nstrs(char **const strs, const size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(strs[i]);
		++i;
	}
	free(strs);
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
	else
		print_format_error(strerror(errno));
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
			free_nstrs(lines, line_count);
			return (NULL);
		}
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
	else
		print_format_error(strerror(errno));
	if (fd != INVALID_FD)
		close(fd);
	return (file_content);
}
