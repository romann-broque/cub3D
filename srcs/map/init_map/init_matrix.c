/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:15:46 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/06 16:16:22 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fill_with_empty_case(char *str, const size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		str[i] = SPACE;
		++i;
	}
	str[i] = '\0';
}

static void	fill_matrix(
	char **matrix,
	const size_t height,
	const size_t width,
	const char *const lines)
{
	size_t	i;
	size_t	j;
	size_t	offset;

	offset = 0;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width
			&& lines[offset + j] != '\0' && lines[offset + j] != '\n')
		{
			matrix[i][j] = lines[offset + j];
			++j;
		}
		fill_with_empty_case(matrix[i] + j, width - j);
		offset += j + (lines[offset + j] == '\n');
		++i;
	}
}

char	**init_matrix(
	const size_t height,
	const size_t width,
	const char *const lines
	)
{
	char **const	matrix = (char **)malloc(height * sizeof(char *));
	size_t			i;

	if (matrix == NULL)
		return (NULL);
	i = 0;
	while (i < height)
	{
		matrix[i] = (char *)malloc((width + 1) * sizeof(char));
		if (matrix[i] == NULL)
		{
			free_strs(matrix);
			return (NULL);
		}
		++i;
	}
	fill_matrix(matrix, height, width, lines);
	return (matrix);
}
