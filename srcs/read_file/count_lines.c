/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:20:53 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/16 14:55:41 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_empty_line(const char *line)
{
	while (*line == SPACE || *line == NEWLINE)
		++line;
	return (*line == END_CHAR);
}

size_t	count_empty_lines(char *const *const lines)
{
	size_t	count;

	count = 0;
	while (lines[count] != NULL && is_empty_line(lines[count]))
		++count;
	return (count);
}
