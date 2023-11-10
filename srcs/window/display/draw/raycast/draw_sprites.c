/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jess <jess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:33:58 by jess              #+#    #+#             */
/*   Updated: 2023/11/10 16:20:02 by jess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_sprite_tex_x(
	const t_sprite sprite,
	const int sprite_height_width,
	const int sprite_screen_x,
	const int i)
{
	return((256 * (i - (-sprite_height_width / 2 + sprite_screen_x)) *
			sprite.texture->width / sprite_height_width) / 256);
}

static void	draw_sprite_pixel(
	const t_sprite sprite,
	const t_pos transform,
	const int sprite_screen_x,
	const int sprite_height_width
)
{
	int		tex_x;
	size_t	i;
	size_t	j;

	i = sprite.sprite_start.x;
	while (i < sprite.sprite_end.x)
	{
		tex_x = get_sprite_tex_x(sprite, sprite_height_width, sprite_screen_x, i);
		if (transform.y > 0 && i > 0 && i < WINDOW_WIDTH && transform.y < /* hitpoints[i]*/)
		{
			j = sprite.sprite_start.y;
			while (j < sprite.sprite_end.y)
			{
				display_sprite_vertical();
				j++;
			}
		}
		i++;
	}
}

static void	draw_sprite(
	t_sprite sprite,
	const t_pos transform
)
{
	const int	sprite_height_width = abs((int)(WINDOW_HEIGHT / transform.y));
	const int	sprite_screen_x = (int)((WINDOW_WIDTH / 2) *
			(1 + transform.x / transform.y));

	sprite.sprite_start = init_sprite_start(
			sprite_height_width, sprite_screen_x);
	sprite.sprite_end = init_sprite_end(
			sprite_height_width, sprite_screen_x);
	draw_sprite_pixel(sprite, transform, sprite_screen_x, sprite_height_width);
}

static void	transform_sprite(const t_sprite sprite, const t_player player)
{
	const double	inv_det = get_inv_det(player);
	const t_pos		sprite_pos = get_sprite_position_to_camera(sprite, player);
	const t_pos		transform = get_transformed_sprite_position(
			sprite, inv_det, sprite_pos, player);

	draw_sprite(sprite, transform);
}
 
void	display_sprite(t_win *const window)
{
	const t_sprite	*sprite = &(window->map->sprite_array);
	size_t			i;

	i = 0;
	sort_sprites(window);
	while (i < window->map->sprite_count)
	{
		if (sprite[i].is_viewed == true)
			transform_sprite(sprite[i], window->map->player);
		i++;
	}
}
