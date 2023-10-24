/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_move_backward.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 08:29:10 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/24 08:34:56 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_backward(t_win *const ptr)
{
	t_map *const	map = ptr->map;
	const double	move_speed = 0.05;

	if (can_move_forward_x(map, -move_speed) == true)
		translate_player_x(&(map->player), -move_speed);
	if (can_move_forward_y(map, -move_speed) == true)
		translate_player_y(&(map->player), -move_speed);
	printf("Current player position -> (%lf;%lf)\n",
		map->player.pos.x, map->player.pos.y);
	return (EXIT_SUCCESS);
}
