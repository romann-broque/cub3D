/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_rotation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jess <jess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:17:11 by lechon            #+#    #+#             */
/*   Updated: 2023/11/07 15:13:46 by jess             ###   ########.fr       */
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

static void	rotate_side(
			t_player *const player,
			const double deg_speed
)
{
	const double	rad_speed = convert_deg_to_rad(deg_speed);

	rotate_vect(&(player->dir), rad_speed);
	rotate_vect(&(player->plane), rad_speed);
}

int	mouse_move(int x, __attribute__((unused))int y, t_win *const window)
{
	static int	prev_x = WINDOW_WIDTH / 2;

	if (window->is_mouse_in_window == true)
	{
		mlx_mouse_move(window->mlx_ptr, window->win_ptr,
			WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
		if (x == prev_x)
			return (EXIT_SUCCESS);
		else if (x < prev_x)
			rotate_side(&(window->map->player),
				-ROTATE_SPEED * MOUSE_ROTATE_COEFF);
		else if (x > prev_x)
			rotate_side(&(window->map->player),
				ROTATE_SPEED * MOUSE_ROTATE_COEFF);
		prev_x = x;
	}
	return (EXIT_SUCCESS);
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
