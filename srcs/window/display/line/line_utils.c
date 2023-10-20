/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:46:19 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/20 11:59:18 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	are_pixels_out(const double x1, const double y1,
					const double x2, const double y2)
{
	if (x1 >= 0 && x1 <= WINDOW_WIDTH && x2 >= 0 && x2 <= WINDOW_WIDTH)
		return ((y1 < 0 && y2 < 0)
			|| (y1 > WINDOW_HEIGHT && y2 > WINDOW_HEIGHT));
	else if (y1 >= 0 && y1 <= WINDOW_HEIGHT && y2 >= 0 && y2 <= WINDOW_HEIGHT)
		return ((x1 < 0 && x2 < 0)
			|| (x1 > WINDOW_WIDTH && x2 > WINDOW_WIDTH));
	return (((x1 < 0 && x2 < 0) || (x1 > WINDOW_WIDTH && x2 > WINDOW_WIDTH))
		&& ((y1 < 0 && y2 < 0) || (y1 > WINDOW_HEIGHT && y2 > WINDOW_HEIGHT)));
}

bool	is_line_printable(t_line *line)
{
	return (are_pixels_out(
			line->pos1.x, line->pos1.y,
			line->pos2.x, line->pos2.y) == false);
}

bool	are_crd_same(const double c1, const double c2)
{
	return ((int)c1 == (int)c2);
}

bool	are_pos_same(const t_pos pos1, const t_pos pos2)
{
	return ((are_crd_same(pos1.x, pos2.x) == true)
		&& (are_crd_same(pos1.y, pos2.y) == true));
}
