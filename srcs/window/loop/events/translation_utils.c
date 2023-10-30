/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:03:14 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/30 22:04:43 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_pos	get_dir_speed(
	const t_vect player_dir,
	const double move_speed
)
{
	t_pos	dir_speed;

	set_pos(&(dir_speed),
		player_dir.x * move_speed,
		player_dir.y * move_speed);
	return (dir_speed);
}

static t_pos	get_translated_pos(
	const t_map *const map,
	const t_pos player_pos,
	const t_vect player_dir,
	const double move_speed
	)
{
	const double	step_move = STEP_SIZE / fabs(move_speed);
	const t_vect	dir_speed = get_dir_speed(player_dir, move_speed);
	t_pos			new_pos;
	t_pos			check_pos;
	double			i;

	new_pos = player_pos;
	i = 0;
	while (i < 1.0)
	{
		check_pos.x = player_pos.x + dir_speed.x * i;
		check_pos.y = player_pos.y + dir_speed.y * i;
		if (is_wall(map, check_pos.x, check_pos.y))
		{
			new_pos.x = (is_wall(map, check_pos.x, new_pos.y) == false)
				* (player_pos.x + dir_speed.x * fmax(0.0, i - step_move));
			new_pos.y = (is_wall(map, new_pos.x, check_pos.y) == false)
				* (player_pos.y + dir_speed.y * fmax(0.0, i - step_move));
		}
		else
			new_pos = check_pos;
		i += step_move;
	}
	return (new_pos);
}

void	translate_side(
	t_map *const map,
	t_player *const player,
	const double move_speed
)
{
	t_vect	side_dir;

	set_vect(&side_dir, player->dir.y, -player->dir.x);
	player->pos = get_translated_pos(map, player->pos, side_dir, move_speed);
}

void	translate_frontback(
	t_map *const map,
	t_player *const player,
	const double move_speed
)
{
	player->pos = get_translated_pos(map, player->pos, player->dir, move_speed);
}
