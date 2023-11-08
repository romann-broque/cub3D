/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_loop.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:14:28 by lechon            #+#    #+#             */
/*   Updated: 2023/11/08 09:42:32 by rbroque          ###   ########.fr       */
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

	// mouse_click.c

int				mouse_click(
					const int click,
					__attribute__((unused))int x,
					__attribute__((unused))int y,
					t_win *const window);

/////////////////////////////////////////
/////			events				/////
/////////////////////////////////////////

	// e_close_window.c

int				close_window(t_win *const ptr);

	// e_rotation.c

int				mouse_move(int x, __attribute__((unused))int y,
					t_win *const window);
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

	// e_open_door.c

int				open_door(t_win *const ptr);

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
