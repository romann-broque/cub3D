/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 07:28:15 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/19 07:30:21 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	convert_deg_to_rad(const double degrees)
{
	return (degrees * (M_PI / 180.0));
}

double	convert_rad_to_deg(const double radian)
{
	return (radian * (180 / M_PI));
}
