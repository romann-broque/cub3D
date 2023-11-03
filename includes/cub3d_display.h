/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_display.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:12:25 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/03 13:59:46 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_DISPLAY_H
# define CUB3D_DISPLAY_H

# include "cub3d.h"

/////////////////////////////////////////////////////////////////////////////
/////																	/////
/////								DISPLAY								/////
/////																	/////
/////////////////////////////////////////////////////////////////////////////

// display_window.c

void		display_window_content(t_win *const window);
void		display_window(t_win *const window);

// display_map.c

void		display_map(t_win *const window);
void		display_minimap(t_win *const window);

// display_grid.c

void		display_grid(t_win *const window);

// display_grid_utils.c

bool		is_closed_to_player(
				const t_map *const map,
				const size_t x, const size_t y);
t_pos		get_offset(const t_pos player_pos);

// display_player.c

void		display_player_on_map(t_win *const window);
void		display_player_on_minimap(t_win *const window);

/////////////////////////////////////////
/////				draw			/////
/////////////////////////////////////////

	// find_screen_pos.c

t_pos		find_map_screen_pos(t_win *const window,
				const t_pos *const pos);
t_pos		find_minimap_screen_pos(t_win *const window,
				const t_pos *const pos);

	// draw_on_map.c

void		draw_square_on_map(t_win *const window,
				const t_pos *const pos, const size_t size,
				const int color);
void		draw_pos_on_map(t_win *const window,
				const t_pos *const pos, const int color);
void		draw_coordinate_on_map(t_win *const window,
				const double x, const double y,
				const int color);
void		draw_line_on_map(t_win *const window,
				const t_pos *const pos1, const t_pos *const pos2,
				const int color);
void		draw_tile_on_map(t_win *const window,
				const t_pos *const pos);

	// draw_on_minimap.c

void		draw_square_on_minimap(t_win *const window,
				const t_pos *const pos, const size_t size,
				const int color);
void		draw_pos_on_minimap(t_win *const window,
				const t_pos *const pos, const int color);
void		draw_coordinate_on_minimap(t_win *const window,
				const double x, const double y,
				const int color);
void		draw_line_on_minimap(t_win *const window,
				const t_pos *const pos1, const t_pos *const pos2,
				const int color);
void		draw_tile_on_minimap(
				t_win *const window,
				const t_pos *const pos);

	// draw_tile.c

void		draw_tile(
				t_win *const window,
				const t_pos *const pos,
				const t_pos *const screen_pos);

	// draw_square.c

void		draw_square(t_win *const window,
				const t_pos *const screen_pos,
				const size_t size,
				const int color);

	// put_pixel.c

void		put_pixel(t_data *data,
				const int x, const int y, const int color);
void		put_tile_pixel(t_win *const window,
				const size_t x, const size_t y,
				const unsigned int color);

/////////////////////////////////////////
/////			raycast				/////
/////////////////////////////////////////

		// draw_vertical.c

void		draw_vertical(
				t_win *const window,
				const t_cast *const cast,
				const double perp_wall_dist,
				const int x);

		// draw_vertical_utils.c

t_pos		init_wall_end(const int lineheight,
				const int height, const int x);
t_pos		init_wall_start(const int lineheight,
				const int height, const int x);
t_texture	*get_texture_from_side(
				t_texture	textures_array[TEXTURE_COUNT],
				const t_side side);
void		set_texture_start_pos(
				t_win *const window,
				const t_side side,
				const int lineheight,
				const double wall_start_y);

		// get_texture_pos.c

int			get_tex_x(const t_cast *const cast,
				const t_texture texture);
t_pos		get_floor_pos(t_win *const window,
				const int y, const t_pos *floor_wall,
				const double perp_wall_dist);

		// get_texture_color.c

uint32_t	get_color_from_floor_pos(t_win *const window,
				const t_pos *const curr_floor);
uint32_t	get_color_from_ceil_pos(t_win *const window,
				const t_pos *const curr_floor);
uint32_t	get_wall_texture(
				const t_cast *const cast,
				t_texture texture,
				const int tex_x);

/////////////////////////////////////////
/////			line				/////
/////////////////////////////////////////

	// init_line.c

void		init_line(t_line *line, const t_pos pos3, const t_pos pos2);
void		init_line_in_minimap(t_line *line,
				const t_pos pos1, const t_pos pos2);

	// line_utils.c

bool		is_pos_in_screen(const t_pos *const pos);
bool		is_line_printable(t_line *line);
bool		are_crd_same(const double c1, const double c2);
bool		are_pos_same(const t_pos pos1, const t_pos pos2);

	// put_line.c

void		put_line(t_data *data,
				const t_pos pos1, const t_pos pos2, const int color);
void		put_line_in_minimap(t_data *data,
				const t_pos pos1, const t_pos pos2, const int color);

	// refresh.c

void		refresh(t_win *window);

#endif
