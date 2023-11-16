/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_dimensions_valid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:31:37 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/01 18:31:57 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_power_of_two(const int nb)
{
	return (nb > 0 && (nb & (nb - 1)) == 0);
}

bool	are_dimensions_valid(const int height, const int width)
{
	return (is_power_of_two(height) && is_power_of_two(width));
}
