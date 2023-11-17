/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_miscellaneous.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:09:05 by lechon            #+#    #+#             */
/*   Updated: 2023/11/17 12:21:33 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_MISCELLANEOUS_H
# define CUB3D_MISCELLANEOUS_H

# include "cub3d.h"

/////////////////////////////////////////////////////////////////////////////
/////																	/////
/////							MISCELLANEOUS							/////
/////																	/////
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////
/////			  math				/////
/////////////////////////////////////////

	// conversion.c

double			convert_deg_to_rad(const double degrees);
double			convert_rad_to_deg(const double radian);

	// are_dimensions_valid.c

bool			are_dimensions_valid(const int height, const int width);

	// distance.c

double			square_dist(const t_pos *const pos1, const t_pos *const pos2);

/////////////////////////////////////////
/////			  print				/////
/////////////////////////////////////////

	// print_format_error.c

void			print_format_error(const char *const error_message);

	// print_format_warning.c

void			print_format_warning(const char *const warning_message);

	// print_help.c

void			print_help(void);

#endif
