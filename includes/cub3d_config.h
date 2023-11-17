/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_config.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:10:33 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/17 12:23:06 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_CONFIG_H
# define CUB3D_CONFIG_H

# include "cub3d.h"

/////////////////////////////////////////////////////////////////////////////
/////																	/////
/////								CONFIG								/////
/////																	/////
/////////////////////////////////////////////////////////////////////////////

// attribute_utils.c

bool					is_config_complete(const t_config *const config);
bool					is_valid_dark_value(const char *const value);
int						fill_attribute(t_config *const config,
							const enum e_attribute_type type,
							char *const *const values);
enum e_attribute_type	find_attribute_type(const char *name);

// build_attribute_from_sequence.c

int						build_attribute_from_sequence(
							t_config *const config,
							char *const *const sequence);

// init_config.c

void					init_config(t_config *const config);

// build_config.c

ssize_t					build_config(t_config *const config,
							char *const *const lines,
							void *const mlx_ptr, void *const win_ptr);

// check_complete_config.c

ssize_t					check_complete_config(ssize_t offset,
							const int attribute_status,
							const t_config *const config);

// free_config.c

void					free_config(t_config *const config,
							void *const mlx_ptr);

// is_config_sequence_valid.c

bool					is_sequence_empty(char *const *const sequence);
bool					is_sequence_format_valid(char *const *const sequence);
bool					is_sequence_valid(char *const *const sequence);

/////////////////////////////////////////
/////			  color				/////
/////////////////////////////////////////

	// is_rgb.c

bool					is_rgb(const char *const str);

	// get_color_from_rgb.c

uint32_t				get_color_from_rgb(const char *const rgb_str);

	// set_color.c

void					set_color(t_config *const config);
unsigned int			change_brightness(const unsigned int color,
							const double factor);

#endif
