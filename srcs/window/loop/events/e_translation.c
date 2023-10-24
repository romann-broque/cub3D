/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_translation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 08:39:33 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/24 09:15:49 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_forward(t_win *const ptr)
{
	t_map *const	map = ptr->map;

	if (can_translate_forward_x(map, MOVE_SPEED) == true)
		translate_player_backfront_x(&(map->player), MOVE_SPEED);
	if (can_translate_forward_y(map, MOVE_SPEED) == true)
		translate_player_backfront_y(&(map->player), MOVE_SPEED);
	return (EXIT_SUCCESS);
}

int	move_backward(t_win *const ptr)
{
	t_map *const	map = ptr->map;

	if (can_translate_forward_x(map, -MOVE_SPEED) == true)
		translate_player_backfront_x(&(map->player), -MOVE_SPEED);
	if (can_translate_forward_y(map, -MOVE_SPEED) == true)
		translate_player_backfront_y(&(map->player), -MOVE_SPEED);
	return (EXIT_SUCCESS);
}

int	move_left(t_win *const ptr)
{
	t_map *const	map = ptr->map;

	if (can_translate_side_x(map, MOVE_SPEED) == true)
		translate_player_side_x(&(map->player), MOVE_SPEED);
	if (can_translate_side_y(map, MOVE_SPEED) == true)
		translate_player_side_y(&(map->player), MOVE_SPEED);
	return (EXIT_SUCCESS);
}

int	move_right(t_win *const ptr)
{
	t_map *const	map = ptr->map;

	if (can_translate_side_x(map, -MOVE_SPEED) == true)
		translate_player_side_x(&(map->player), -MOVE_SPEED);
	if (can_translate_side_y(map, -MOVE_SPEED) == true)
		translate_player_side_y(&(map->player), -MOVE_SPEED);
	return (EXIT_SUCCESS);
}
