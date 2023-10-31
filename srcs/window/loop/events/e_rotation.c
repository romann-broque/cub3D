/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_rotation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechon <lechon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:17:11 by lechon            #+#    #+#             */
/*   Updated: 2023/10/31 14:52:43 by lechon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	rotate_vect(t_vect *const object, const double rad_speed)
{
	const double	old_x = object->x;

	object->x = object->x * cos(rad_speed)
		- object->y * sin(rad_speed);
	object->y = old_x * sin(rad_speed)
		+ object->y * cos(rad_speed);
}

void	rotate_side(
			t_player *const player,
			const double deg_speed
)
{
	const double	rad_speed = convert_deg_to_rad(deg_speed);

	rotate_vect(&(player->dir), rad_speed);
	rotate_vect(&(player->plane), rad_speed);
}

int	rotate_right(t_win *const ptr)
{
	t_player *const	player = &(ptr->map->player);

	rotate_side(player, ROTATE_SPEED);
	return (EXIT_SUCCESS);
}

int	rotate_left(t_win *const ptr)
{
	t_player *const	player = &(ptr->map->player);

	rotate_side(player, -ROTATE_SPEED);
	return (EXIT_SUCCESS);
}
