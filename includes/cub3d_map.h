/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:12:07 by lechon            #+#    #+#             */
/*   Updated: 2023/11/14 10:15:48 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_MAP_H
# define CUB3D_MAP_H

# include "cub3d.h"
# include "cub3d_defines.h"

/////////////////////////////////////////////////////////////////////////////
/////																	/////
/////								   MAP								/////
/////																	/////
/////////////////////////////////////////////////////////////////////////////

// free_map.c

void			free_tile_matrix(t_tile **const matrix, const size_t size);
void			free_map(t_map *const map);

// print_map.c

void			print_map(const t_map *const map);

/////////////////////////
////     init_map    ////
/////////////////////////

	// init_map.c

t_map			*init_map(char *const *const lines);

	// init_matrix.c

t_tile			**init_matrix(
					const size_t height,
					const size_t width,
					char *const *const lines);

/////////////////////////
////   is_map_valid  ////
/////////////////////////

	// is_map_closed.c

bool			is_map_closed(const t_map *const map);

	// is_map_closed_utils.c

bool			is_closed_dfs(const t_map *const map,
					const ssize_t x, const ssize_t y);

	// is_map_content_valid.c

bool			is_map_content_valid(const t_map *const map);

	// is_map_unique.c

bool			is_map_unique(const t_map *const map);

	// are_doors_surrounded.c

bool			are_doors_surrounded(const t_map *const map);

	// is_map_valid.c

bool			is_map_valid(t_map *const map);

/////////////////////////
////	player		 ////
/////////////////////////

	// get_player.c

t_player		get_player(t_map *const map);

	// set_pos.c

void			set_pos(t_pos *const pos,
					const double x, const double y);
void			set_vect(t_vect *const vect,
					const double x, const double y);

/////////////////////////
////	raycast		 ////
/////////////////////////

	// raycaster.c

t_cast			raycast(t_win *const window,
					const size_t x);
void			raycaster(t_win *const window,
					t_pos hitpoint_array[WINDOW_WIDTH],
					double distance_array[WINDOW_WIDTH]);

	// get_vect.c

t_vect			get_ray(const t_player player, const size_t x);
t_vect			get_delta_dist(const t_vect ray);
t_vect			get_step_from_ray(const t_vect ray);
t_vect			get_side_dist(
					const t_pos pos, const t_vect ray,
					const t_vect delta_dist);

	// cast_utils.c

void			set_hitpoint(t_cast *const cast,
					const t_pos player_pos,
					const size_t x, const size_t y);
void			set_side(t_side *const side, const t_vect step);

	// dda.c

t_cast			dda(t_map *const map, const t_pos pos,
					const t_vect ray, const t_vect delta_dist);

/////////////////////////
////     sprites     ////
/////////////////////////

	// sprite_utils.c

bool			is_sprite(const t_map *const map, const size_t x,
					const size_t y);
void			set_sprite_as_viewed(t_map *const map,
					const double x,
					const double y);
bool			is_sprite_crossable(
					const t_map *const map,
					const double x,
					const double y);

	// init_sprites.c

void			init_sprites(t_map *const map, const t_config *const config);

	// refresh_sprites.c

void			refresh_sprites(t_map *const map);

/////////////////////////
////     	tile     ////
/////////////////////////

// door.c

bool			is_tile_door(const t_tile *const tile);
void			refresh_door(const t_player *const player, t_tile *const door);

// refresh_tiles.c

void			refresh_tiles(t_map *const map);

// tile_utils.c

bool			is_on_tile(const t_pos *const pos,
					const size_t x,
					const size_t y);
t_tile			*get_tile_from_map(const t_map *const map,
					const size_t x,
					const size_t y);

// tile_mark.c

bool			is_marked(const t_map *const map,
					const size_t x,
					const size_t y);
void			mark_as_viewed(const t_map *const map,
					const size_t x,
					const size_t y);

// tile_type.c

bool			is_blank(
					const t_map *const map,
					const size_t x, const size_t y);
bool			is_wall(
					const t_map *const map,
					const size_t x, const size_t y);
bool			is_door(
					const t_map *const map,
					const size_t x,
					const size_t y);
bool			is_ground(
					const t_map *const map,
					const size_t x, const size_t y);

bool			is_player(const t_map *const map,
					const size_t x, const size_t y);

#endif
