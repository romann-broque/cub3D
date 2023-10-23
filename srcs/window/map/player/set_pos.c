/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 06:32:11 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/19 07:48:40 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_pos(
	t_pos *const pos,
	const double x,
	const double y
	)
{
	pos->x = x;
	pos->y = y;
}

void	set_vect(
	t_vect *const vect,
	const double x,
	const double y
)
{
	set_pos(vect, x, y);
}
