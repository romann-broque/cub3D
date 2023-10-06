/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:15:46 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/06 14:34:18 by rbroque          ###   ########.fr       */
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

	i = 0;
	while (i < height)
	{
		printf("i -> %zu\n", i);
		j = 0;
		while (j < width && lines[i * width + j] != '\n')
		{
			printf("-> %c\n", matrix[i][j]);
			matrix[i][j] = lines[i * width + j];
			printf("j -> %zu\n", j);
			++j;
		}
		fill_with_empty_case(matrix[i] + j, width - j);
		++i;
	}
}

char	**init_matrix(
	const size_t height,
	const size_t width,
	const char *const lines
	)
{
	char **const	matrix = (char **)ft_calloc(height * width, sizeof(char *));

	if (matrix == NULL)
		return (NULL);
	fill_matrix(matrix, height, width, lines);
	return (matrix);
}
