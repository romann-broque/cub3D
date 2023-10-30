/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_window.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:17:42 by lechon            #+#    #+#             */
/*   Updated: 2023/10/26 16:10:22 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_WINDOW_H
# define CUB3D_WINDOW_H

# include "cub3d.h"

/////////////////////////////////////////////////////////////////////////////
/////																	/////
/////								WINDOW								/////
/////																	/////
/////////////////////////////////////////////////////////////////////////////

// init_window.c

void			init_window(t_win *const window,
					char *const *const file_content);

// free_window.c

void			free_window(t_win *const window);

// is_window_complete.c

bool			is_window_complete(t_win *const window);

/////////////////////////////////////////
/////			data				/////
/////////////////////////////////////////

	// init_data.c

void			init_data(void *const mlx_ptr, t_data *const dest);

	// free_data.c

void			free_data(const t_data *data, void *const mlx_ptr);

#endif