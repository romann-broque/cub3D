/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_config.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:10:33 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/05 11:24:15 by rbroque          ###   ########.fr       */
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

int				build_attribute_from_sequence(
					t_config *const config, char *const *const sequence);

// init_config.c

void			init_config(t_config *const config);

// build_config.c

ssize_t			build_config(t_config *const config, char *const *const lines,
					void *const mlx_ptr, void *const win_ptr);

// free_config.c

void			free_config(t_config *const config, void *const mlx_ptr);

// print_config.c

void			print_config(t_config *const config);

// is_config_sequence_valid.c

bool			is_sequence_empty(char *const *const sequence);
bool			is_sequence_format_valid(char *const *const sequence);
bool			is_sequence_valid(char *const *const sequence);

/////////////////////////////////////////
/////			  color				/////
/////////////////////////////////////////

	// is_rgb.c

bool			is_rgb(const char *const str);

	// get_color_from_rgb.c

uint32_t		get_color_from_rgb(const char *const rgb_str);

	// set_color.c

void			set_color(t_config *const config);
unsigned int	change_brightness(const unsigned int color,
					const double factor);

#endif
