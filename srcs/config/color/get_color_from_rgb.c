/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_from_rgb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:59:52 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/24 09:34:06 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static unsigned int	sum_rgb(
	const unsigned int red_val,
	const unsigned int green_val,
	const unsigned int blue_val
	)
{
	const unsigned int	red = red_val << 16;
	const unsigned int	green = green_val << 8;
	const unsigned int	blue = blue_val;

	return (red + green + blue);
}

static unsigned int	sum_rgb_str(
	const char *const red_str,
	const char *const green_str,
	const char *const blue_str)
{
	const unsigned int	red = ft_atoi(red_str);
	const unsigned int	green = ft_atoi(green_str);
	const unsigned int	blue = ft_atoi(blue_str);

	return (sum_rgb(red, green, blue));
}

unsigned int	get_color_from_rgb(const char *const rgb_str)
{
	const char	*red_str = rgb_str;
	const char	*green_str = red_str + abs_index(red_str, RGB_SEPARATOR) + 1;
	const char	*blue_str = green_str + abs_index(green_str, RGB_SEPARATOR) + 1;

	return (sum_rgb_str(red_str, green_str, blue_str));
}
