/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:33:58 by jess              #+#    #+#             */
/*   Updated: 2023/11/13 09:38:08 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static int	get_sprite_tex_x(
// 	const t_sprite *const sprite,
// 	const int sprite_height_width,
// 	const int sprite_screen_x,
// 	const int i)
// {
// 	return ((256 * (i - (-sprite_height_width / 2 + sprite_screen_x))
// 			* sprite->texture->width / sprite_height_width) / 256);
// }

// static int	get_sprite_tex_y(
// 	const t_sprite *const sprite,
// 	const int sprite_height_width,
// 	const size_t y
// )
// {
// 	const int	d = y * 256 - WINDOW_HEIGHT * 128 + sprite_height_width * 128;
// 	const int	tex_y = ((d * sprite->texture->height) / sprite_height_width) / 256;

// 	return (tex_y);
// }

static void	draw_sprite_pixel(
	t_data *const data,
	const t_sprite *const sprite,
	const t_pos transform,
	const int sprite_screen_x,
	const int sprite_height_width
)
{
	// t_pos	tex_pos;
	size_t	i;
	size_t	j;

	i = sprite->sprite_start.x;
	while (i < sprite->sprite_end.x)
	{
		if (transform.y > 0 && i > 0 && i < WINDOW_WIDTH)
		{
			// tex_pos.x = get_sprite_tex_x(sprite, sprite_height_width,
			// 		sprite_screen_x, i);
			j = sprite->sprite_start.y;
			while (j < sprite->sprite_end.y)
			{
				// tex_pos.y = get_sprite_tex_y(sprite, sprite_height_width, i, j);
				put_pixel(data, i, j, WHITE);
				j++;
			}
		}
		i++;
	}
}

static void	draw_sprite(
	t_data *data,
	t_sprite *const sprite,
	const t_pos transform
)
{
	const int	sprite_height_width = abs((int)(WINDOW_HEIGHT / transform.y));
	const int	sprite_screen_x = (int)((WINDOW_WIDTH / 2)
			* (1 + transform.x / transform.y));

	sprite->sprite_start = init_sprite_start(
			sprite_height_width, sprite_screen_x);
	sprite->sprite_end = init_sprite_end(
			sprite_height_width, sprite_screen_x);
	draw_sprite_pixel(data, sprite, transform, sprite_screen_x, sprite_height_width);
}

static t_pos	transform_sprite(
	t_sprite *const sprite,
	const t_player *const player
	)
{
	const double	inv_det = get_inv_det(player);
	const t_pos		sprite_pos = get_sprite_position_to_camera(sprite, player);
	const t_pos		transform = get_transformed_sprite_position(
			inv_det, sprite_pos, player);

	return (transform);
}

void	display_sprite(t_win *const window)
{
	t_sprite *const	sprites = window->map->sprite_array;
	t_pos			transform;
	size_t			i;

	i = 0;
	sort_sprites(window);
	while (i < window->map->sprite_count)
	{
		if (sprites[i].is_viewed == true)
		{
			transform = transform_sprite(sprites + i, &(window->map->player));
			draw_sprite(&(window->data), sprites + i, transform);
		}
		i++;
	}
}
