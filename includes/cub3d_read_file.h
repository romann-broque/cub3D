/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_read_file.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:16:19 by lechon            #+#    #+#             */
/*   Updated: 2023/10/26 15:36:54 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_READ_FILE_H
# define CUB3D_READ_FILE_H

# include "cub3d.h"

/////////////////////////////////////////
/////			 read_file			/////
/////////////////////////////////////////

// get_file.c

char			**get_file(const char *const file_name);

// is_file_valid.c

bool			is_file_valid(const char *const filename, const int fd);

#endif