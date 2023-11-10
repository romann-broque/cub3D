/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jess <jess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:37:04 by jess              #+#    #+#             */
/*   Updated: 2023/11/10 10:45:27 by jess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	swap_sprites(t_win *const window)
{
	size_t		i;
	size_t		j;
	t_sprite	tmp;
	t_sprite	*sprite;

	i = 0;
	sprite = &(window->map->sprite_array);
	while (i < window->map->sprite_count)
	{
		j = i + 1;
		while (j < window->map->sprite_count)
		{
			if (sprite[i].sq_distance < sprite[j].sq_distance)
			{
				tmp = sprite[i];
				sprite[i] = sprite[j];
				sprite[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static double	calculate_sprite_distance(
	double pos_x,
	double pos_y,
	double sprite_x,
	double sprite_y
)
{
	const double	dist1 = pos_x - sprite_x;
	const double	dist2 = pos_y - sprite_y;

	return (pow(dist1, 2) + pow(dist2, 2));
}
static void	set_sprite_distance(t_win *const window)
{
	const t_player	player = window->map->player;
	t_sprite		*sprite;
	size_t			i;

	i = 0;
	sprite = &(window->map->sprite_array);
	while (i < window->map->sprite_count)
	{
		if (sprite[i].is_viewed == true)
			sprite[i].sq_distance = calculate_sprite_distance(
				player.pos.x, player.pos.y, sprite[i].pos.x, sprite[i].pos.y);
		else
			sprite[i].sq_distance = 0;
		i++;
	}
}

void	sort_sprites(t_win *const window)
{
	set_sprite_distance(window);
	swap_sprites(window);
}
