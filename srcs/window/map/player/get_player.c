/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 07:20:28 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/23 16:26:46 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_pos	get_player_pos(t_map *const map)
{
	t_pos	pos;
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (is_player(map, x, y))
			{
				pos.x = x + PLAYER_XOFFSET;
				pos.y = y + PLAYER_YOFFSET;
			}
			++x;
		}
		++y;
	}
	return (pos);
}

static t_vect	get_player_dir(
	t_map *const map,
	const t_pos player_pos
	)
{
	static const t_vect	dir_array[] = {
	{.x = 0, .y = -1},
	{.x = 0, .y = 1},
	{.x = -1, .y = 0},
	{.x = 1, .y = 0}
	};
	const char			dir_char = map->matrix
	[(size_t)player_pos.y]
	[(size_t)player_pos.x].tile_char;
	const size_t		index = abs_index(VALID_CHAR_DIR, dir_char);
	t_vect				dir;

	set_pos(&dir, dir_array[index].x, dir_array[index].y);
	return (dir);
}

static t_vect	get_player_plane(const t_vect player_dir)
{
	const double	plane_norm = tan(convert_deg_to_rad(FOV) / 2);
	t_vect			plane;

	set_pos(&plane, -player_dir.y * plane_norm, player_dir.x * plane_norm);
	return (plane);
}

t_player	get_player(t_map *const map)
{
	t_player	player;

	player.pos = get_player_pos(map);
	player.dir = get_player_dir(map, player.pos);
	player.plane = get_player_plane(player.dir);
	printf("\nPlayer:\n");
	printf("pos->%lf;%lf\n", player.pos.x, player.pos.y);
	printf("dir->%lf;%lf\n", player.dir.x, player.dir.y);
	printf("plane->%lf;%lf\n", player.plane.x, player.plane.y);
	return (player);
}
/*
	Rotation example

	double	angle = 3.5;

	set_pos(&(player.dir),
		player.dir.x * cos(angle) - player.dir.y * sin(angle),
		player.dir.x * sin(angle) + player.dir.y * cos(angle));
	set_pos(&(player.plane),
		player.plane.x * cos(angle) - player.plane.y * sin(angle),
		player.plane.x * sin(angle) + player.plane.y * cos(angle)); 
*/