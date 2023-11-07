/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_loop.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jess <jess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:14:28 by lechon            #+#    #+#             */
/*   Updated: 2023/11/07 12:13:48 by jess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_LOOP_H
# define CUB3D_LOOP_H

# include "cub3d.h"

/////////////////////////////////////////////////////////////////////////////
/////																	/////
/////								LOOP								/////
/////																	/////
/////////////////////////////////////////////////////////////////////////////

	// loop.c

void			loop(t_win *const window);

	// keyboard.c

int				browse_mapping(t_win *window);
int				key_press(const int key, t_win *window);
int				key_release(const int key, t_win *window);

	// keyboard_utils.c

void			set_key_status(t_win *const window,
					const int key, const bool is_pressed);
t_event_mapping	*get_key_mapping(void);
ssize_t			find_key_index(const t_key *keys, const int key);
bool			is_same_key_in(const t_key *const keys, const t_key key);

	// mouse_move.c

int				mouse_move(int x, int y, t_win *const window);

	// mouse_click.c

int				mouse_click(
					const int click,
					__attribute__((unused))int x,
					__attribute__((unused))int y,
					t_win *const window);

	// mouse_invisible.c

bool			is_pair(const int nb);
Cursor			create_invisible_cursor(Display *display, Window rootWindow);
void			hide_window_cursor(Display *display, Cursor *invisible_cursor);
void			display_window_cursor(
					Display *display, Cursor *invisible_cursor);

/////////////////////////////////////////
/////			events				/////
/////////////////////////////////////////

	// e_close_window.c

int				close_window(t_win *const ptr);

	// e_rotation.c

void			rotate_side(
					t_player *const player,
					const double deg_speed);
int				rotate_right(t_win *const ptr);
int				rotate_left(t_win *const ptr);

	// e_translation.c

int				move_forward(t_win *const ptr);
int				move_backward(t_win *const ptr);
int				move_left(t_win *const ptr);
int				move_right(t_win *const ptr);

	// e_map_mod.c

int				enable_map_mod(t_win *const ptr);
int				disable_map_mod(t_win *const ptr);

	// translate.c

void			translate_side(t_map *const map,
					t_player *const player, const double move_speed);
void			translate_frontback(t_map *const map,
					t_player *const player, const double move_speed);

	// get_translated_pos.c

t_pos			get_translated_pos(const t_map *const map,
					const t_pos player_pos, const t_vect player_dir,
					const double move_speed);

#endif
