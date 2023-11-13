/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_translated_pos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:03:14 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/09 13:13:59 by rbroque          ###   ########.fr       */
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

static void	get_new_pos_from_wall_collision(
	t_pos *const new_pos,
	const t_pos *const check_pos,
	const t_map *const map,
	const t_vect move_offset
	)
{
	static const t_pos	*player_pos = NULL;

	if (player_pos == NULL)
		player_pos = &(map->player.pos);
	if (is_crossable(map, check_pos->x, new_pos->y))
		new_pos->x = player_pos->x + move_offset.x;
	if (is_crossable(map, new_pos->x, check_pos->y))
		new_pos->y = player_pos->y + move_offset.y;
}

static t_vect	get_move_offset(
	const t_vect *const dir_speed,
	const double i,
	const double step_move
)
{
	const double	coeff = fmax(0.0, i - step_move);
	t_vect			move_offset;

	set_vect(&move_offset,
		dir_speed->x * coeff,
		dir_speed->y * coeff);
	return (move_offset);
}

t_pos	get_translated_pos(
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
		if (is_crossable(map, check_pos.x, check_pos.y) == false)
			get_new_pos_from_wall_collision(&new_pos, &check_pos,
				map, get_move_offset(&dir_speed, i, step_move));
		else
			new_pos = check_pos;
		i += step_move;
	}
	return (new_pos);
}
