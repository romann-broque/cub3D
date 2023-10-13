/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 06:19:54 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/13 08:37:13 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_uchar(const char *const str)
{
	int	nb;

	return (is_number(str) == true && ft_atoi_safe(&nb, str) == true
		&& nb >= 0 && nb <= UCHAR_MAX);
}

bool	is_rgb(const char *const str)
{
	char	**colors;
	bool	is_rgb_val;

	is_rgb_val = false;
	if (count_c_in_str(str, ',') == 2)
	{
		colors = ft_split(str, ',');
		if (colors == NULL)
			print_format_error(strerror(errno));
		else if (get_size_strs(colors) == 3)
		{
			is_rgb_val = (is_uchar(colors[0])
					&& is_uchar(colors[1])
					&& is_uchar(colors[2]));
		}
		free_strs(colors);
	}
	return (is_rgb_val);
}
