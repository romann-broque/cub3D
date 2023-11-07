/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:58:46 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/07 10:49:52 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_hitpoint(
	t_cast *const cast,
	const t_pos player_pos,
	const size_t x,
	const size_t y
	)
{
	if (cast->side == WEST_FACE || cast->side == EAST_FACE)
	{
		cast->hitpoint.x = x + (cast->step.x == -1);
		cast->hitpoint.y = cast->coeff * (cast->hitpoint.x - player_pos.x)
			+ player_pos.y;
	}
	else
	{
		cast->hitpoint.y = y + (cast->step.y == -1);
		cast->hitpoint.x = (cast->hitpoint.y - player_pos.y) / cast->coeff
			+ player_pos.x;
	}
}

void	set_side(t_side *const side, const t_vect step)
{
	if (*side == WEST_FACE && step.x < 0)
		*side = EAST_FACE;
	else if (*side == NORTH_FACE && step.y > 0)
		*side = SOUTH_FACE;
}
