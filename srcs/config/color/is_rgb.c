/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechon <lechon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 06:19:54 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/01 11:16:04 by lechon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_uchar(const char *const str)
{
	int	nb;

	return (is_number(str) == true && ft_atoi_safe(&nb, str) == true
		&& nb >= 0 && nb <= UCHAR_MAX);
}

bool	are_uchar(char *const *const strs)
{
	size_t	i;

	i = 0;
	while (strs[i] != NULL && is_uchar(strs[i]))
		++i;
	return (strs[i] == NULL);
}

bool	is_rgb(const char *const str)
{
	char	**colors;
	bool	is_rgb_val;

	is_rgb_val = false;
	if (count_c_in_str(str, RGB_SEPARATOR) == RGB_SIZE - 1)
	{
		colors = ft_split(str, RGB_SEPARATOR);
		if (colors == NULL)
			print_format_error(strerror(errno));
		else if (get_size_strs(colors) == RGB_SIZE)
			is_rgb_val = are_uchar(colors);
		free_strs(colors);
	}
	return (is_rgb_val);
}
