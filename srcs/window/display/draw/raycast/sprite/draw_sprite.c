/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:36:03 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/13 21:25:23 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t	get_tex_index_from_time(const t_sprite *const sprite)
{
	size_t	new_index;

	new_index = sprite->time / SPRITE_TIME;
	if (new_index >= sprite->tex_count)
		new_index = 0;
	return (new_index);
}

static void	draw_sprite_pixel(
	t_data *const data,
	const t_sprite *const sprite,
	const t_transform transform,
	const double distance_array[WINDOW_WIDTH]
)
{
	const t_pos	trans_pos = transform.pos;
	size_t		i;

	i = sprite->sprite_start.x;
	while (i < sprite->sprite_end.x)
	{
		if (trans_pos.y > 0 && trans_pos.y < distance_array[i]
			&& i > 0 && i < WINDOW_WIDTH)
			draw_sprite_stripe(data, sprite, &transform, i);
		i++;
	}
}

static void	set_curr_texture(t_sprite *const sprite)
{
	const size_t	tex_index = get_tex_index_from_time(sprite);

	sprite->curr_texture = sprite->textures + tex_index;
}

void	draw_sprite(
	t_data *data,
	t_sprite *const sprite,
	const t_pos transform_pos,
	const double distance_array[WINDOW_WIDTH]
)
{
	const int	sprite_height_width
		= abs((int)(WINDOW_HEIGHT / transform_pos.y));
	const int	sprite_screen_x = (int)((WINDOW_WIDTH / 2)
			* (1 + transform_pos.x / transform_pos.y));
	t_transform	transform;

	sprite->sprite_start = init_sprite_start(
			sprite_height_width, sprite_screen_x);
	sprite->sprite_end = init_sprite_end(
			sprite_height_width, sprite_screen_x);
	transform.pos = transform_pos;
	transform.screen_x = sprite_screen_x;
	transform.square_size = sprite_height_width;
	set_curr_texture(sprite);
	draw_sprite_pixel(data, sprite, transform, distance_array);
}
