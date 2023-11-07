/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:54:53 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/07 14:30:33 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_signd(const double nb)
{
	if (nb < 0)
		return (-1);
	return (1);
}

static size_t	get_nb_points(const double dx, const double dy)
{
	return (round(sqrt(pow(dx, 2) + pow(dy, 2))));
}

static void	set_line(t_line *line, const t_pos pos1, const t_pos pos2)
{
	set_pos(&(line->pos1), pos1.x, pos1.y);
	set_pos(&(line->pos2), pos2.x, pos2.y);
	line->dx = fabs(pos2.x - pos1.x);
	line->sx = get_signd(pos2.x - pos1.x);
	line->dy = -fabs(pos2.y - pos1.y);
	line->sy = get_signd(pos2.y - pos1.y);
	line->error = line->dx + line->dy;
	line->nb_points = get_nb_points(line->dx, line->dy);
}

void	init_line(t_line *line, const t_pos pos1, const t_pos pos2)
{
	set_pos(&(line->min_pos), 0, 0);
	set_pos(&(line->max_pos), WINDOW_WIDTH, WINDOW_HEIGHT);
	set_line(line, pos1, pos2);
}

void	init_line_in_minimap(t_line *line, const t_pos pos1, const t_pos pos2)
{
	static const double	min_x = MINIMAP_XOFFSET;
	static const double	max_x = MINIMAP_XOFFSET
		+ 2 * MINIMAP_RADIUS * (TILE_SIZE - 1) + TILE_SIZE - 1;
	static const double	min_y = MINIMAP_YOFFSET;
	static const double	max_y = MINIMAP_YOFFSET
		+ 2 * MINIMAP_RADIUS * (TILE_SIZE - 1) + TILE_SIZE - 1;

	set_pos(&(line->min_pos), min_x, min_y);
	set_pos(&(line->max_pos), max_x, max_y);
	set_line(line, pos1, pos2);
}
