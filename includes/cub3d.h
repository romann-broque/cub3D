/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:50:43 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/06 14:31:15 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

//////////////
// INCLUDES //
//////////////

# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/////////////
// DEFINES //
/////////////

# define EXPECTED_ARG_COUNT	2
# define INVALID_FD			-1
# define FILE_EXTENSION		".cub"
# define VALID_CHAR			"01 NWES\n"
# define VALID_CHAR_DIR		"NWES"

//// read_map ////

// get_file.c

char	*get_file(const char *const file_name);

// is_file_valid.c

bool	is_file_valid(const char *const filename, const int fd);

// is_map_valid.c

bool	are_characters_valid(char *const content);

#endif