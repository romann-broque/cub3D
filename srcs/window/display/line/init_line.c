/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:54:53 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/20 07:01:53 by rbroque          ###   ########.fr       */
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

void	init_line(t_line *line, const t_pos pos1, const t_pos pos2)
{
	set_pos(&(line->pos1), pos1.x, pos1.y);
	set_pos(&(line->pos2), pos2.x, pos2.y);
	line->dx = fabs(pos1.x - pos2.x);
	line->sx = get_signd(pos1.x - pos2.x);
	line->dy = -fabs(pos1.y - pos2.y);
	line->sy = get_signd(pos1.y - pos2.y);
	line->error = line->dx + line->dy;
	line->nb_points = get_nb_points(line->dx, line->dy);
}
