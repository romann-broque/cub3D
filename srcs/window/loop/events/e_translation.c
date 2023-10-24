/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_translation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 08:39:33 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/24 14:20:41 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_forward(t_win *const ptr)
{
	t_map *const	map = ptr->map;

	translate_frontback(ptr->map, &(map->player), MOVE_SPEED);
	return (EXIT_SUCCESS);
}

int	move_backward(t_win *const ptr)
{
	t_map *const	map = ptr->map;

	translate_frontback(ptr->map, &(map->player), -MOVE_SPEED);
	return (EXIT_SUCCESS);
}

int	move_left(t_win *const ptr)
{
	t_map *const	map = ptr->map;

	translate_side(ptr->map, &(map->player), MOVE_SPEED);
	return (EXIT_SUCCESS);
}

int	move_right(t_win *const ptr)
{
	t_map *const	map = ptr->map;

	translate_side(ptr->map, &(map->player), -MOVE_SPEED);
	return (EXIT_SUCCESS);
}
