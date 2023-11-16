/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 06:28:34 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/10 07:27:08 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	can_put_pixel(
	const t_pos min_pos,
	const t_pos max_pos,
	const t_pos pos
	)
{
	return (floor(pos.x) < max_pos.x
		&& floor(pos.y) < max_pos.y
		&& floor(pos.x) >= min_pos.x
		&& floor(pos.y) >= min_pos.y);
}

static void	put_point(t_data *data, const t_line *const line, const int color)
{
	if (can_put_pixel(line->min_pos, line->max_pos, line->pos1) == true)
		put_pixel(data, line->pos1.x, line->pos1.y, color);
}

static void	plot_line(t_data *data, t_line *const line, const int color)
{
	size_t	i;

	i = 0;
	while (i <= line->nb_points)
	{
		put_point(data, line, color);
		if (are_pos_same(line->pos1, line->pos2) == true)
			break ;
		line->e2 = 2 * line->error;
		if (line->e2 >= line->dy)
		{
			if (are_crd_same(line->pos1.x, line->pos2.x))
				break ;
			line->error += line->dy;
			line->pos1.x += line->sx;
		}
		if (line->e2 <= line->dx)
		{
			if (are_crd_same(line->pos1.y, line->pos2.y))
				break ;
			line->error += line->dx;
			line->pos1.y += line->sy;
		}
		++i;
	}
}

void	put_line(
	t_data *data,
	const t_pos pos1,
	const t_pos pos2,
	const int color
	)
{
	t_line	line;

	init_line(&line, pos1, pos2);
	if (is_line_printable(&line) == true)
		plot_line(data, &line, color);
}

void	put_line_in_minimap(
	t_data *data,
	const t_pos pos1,
	const t_pos pos2,
	const int color
	)
{
	t_line	line;

	init_line_in_minimap(&line, pos1, pos2);
	if (is_line_printable(&line) == true)
		plot_line(data, &line, color);
}
