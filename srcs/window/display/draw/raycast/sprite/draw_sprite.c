/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:36:03 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/13 16:01:38 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_sprite_tex_x(
	const t_sprite *const sprite,
	const int sprite_height_width,
	const int sprite_screen_x,
	const int i)
{
	return ((256 * (i + sprite_height_width / 2 - sprite_screen_x)
			* sprite->texture->width / sprite_height_width) / 256);
}

static int	get_sprite_tex_y(
	const t_sprite *const sprite,
	const int sprite_height_width,
	const size_t y
)
{
	const int	d = y * 256 + (sprite_height_width - WINDOW_HEIGHT) * 128;
	const int	tex_y
		= ((d * sprite->texture->height) / sprite_height_width) / 256;

	return (tex_y);
}

static void	draw_sprite_stripe(
	t_data *const data,
	const t_sprite *const sprite,
	const t_transform *transform,
	const size_t stripe_index
)
{
	uint32_t	color;
	t_pos		tex_pos;
	size_t		i;

	tex_pos.x = get_sprite_tex_x(sprite, transform->square_size,
			transform->screen_x, stripe_index);
	i = sprite->sprite_start.y;
	while (i < sprite->sprite_end.y)
	{
		tex_pos.y = get_sprite_tex_y(sprite, transform->square_size, i);
		color = get_sprite_texture(sprite->texture, tex_pos);
		if (color & WHITE)
			put_pixel(data, stripe_index, i, color);
		++i;
	}
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
	draw_sprite_pixel(data, sprite, transform, distance_array);
}
