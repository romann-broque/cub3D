/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:54:53 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/24 22:30:40 by rbroque          ###   ########.fr       */
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
	return ((size_t)(sqrt(pow(dx, 2) + pow(dy, 2))));
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
	set_pos(&(line->min_pos), MINIMAP_XOFFSET, MINIMAP_YOFFSET);
	set_pos(&(line->max_pos),
		MINIMAP_XOFFSET + 2 * (MINIMAP_RADIUS) * (TILE_SIZE) + TILE_SIZE,
		MINIMAP_YOFFSET + 2 * (MINIMAP_RADIUS) * (TILE_SIZE) + TILE_SIZE);
	set_line(line, pos1, pos2);
}
