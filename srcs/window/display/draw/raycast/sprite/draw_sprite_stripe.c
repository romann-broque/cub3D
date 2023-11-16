/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite_stripe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:23:12 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/16 12:17:57 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_sprite_tex_x(
	const t_texture *const texture,
	const int sprite_height_width,
	const int sprite_screen_x,
	const int i)
{
	return ((POW2_8 * (i + sprite_height_width / 2 - sprite_screen_x)
			* texture->width / sprite_height_width) / POW2_8);
}

static int	get_sprite_tex_y(
	const t_texture *const texture,
	const int sprite_height_width,
	const size_t y
)
{
	const int	d = y * POW2_8 + (sprite_height_width - WINDOW_HEIGHT) * POW2_7;
	const int	tex_y
		= ((d * texture->height) / sprite_height_width) / POW2_8;

	return (tex_y);
}

void	draw_sprite_stripe(
	t_data *const data,
	const t_sprite *const sprite,
	const t_transform *transform,
	const size_t stripe_index
)
{
	uint32_t		color;
	t_pos			tex_pos;
	size_t			i;

	tex_pos.x = get_sprite_tex_x(sprite->curr_texture, transform->square_size,
			transform->screen_x, stripe_index);
	i = sprite->sprite_start.y;
	while (i < sprite->sprite_end.y)
	{
		tex_pos.y = get_sprite_tex_y(sprite->curr_texture,
				transform->square_size, i);
		color = get_sprite_texture(sprite->curr_texture, tex_pos);
		if (color & WHITE)
			put_pixel(data, stripe_index, i, color);
		++i;
	}
}
