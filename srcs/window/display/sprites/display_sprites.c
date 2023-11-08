/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jess <jess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:37:04 by jess              #+#    #+#             */
/*   Updated: 2023/11/08 17:21:02 by jess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sort_sprites(int *order, double *distance)
{
	size_t	i;
	size_t	j;
	double	tmp;

	i = 0;
	while (order[i] != NULL)
	{
		j = i + 1;
		if (distance[i] < distance[j])
		{
			tmp = distance[i];
			distance[i] = distance[j];
			distance[j] = tmp;
		}
		i++;
	}
}

static double	get_sprite_distance(
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

void	set_sprite_distance(t_win *const window)
{
	const t_player	*player = &(window->map->player);
	t_sprite		*sprite;
	size_t			i;

	i = 0;
	sprite = &(window->map->sprite);
	while (i < SPRITES_COUNT)
	{
		sprite->order[i] = i;
		sprite->distance[i] = get_sprite_distance(
			player->pos.x, player->pos.y, sprite->x, sprite->y);
		i++;
	}
}
