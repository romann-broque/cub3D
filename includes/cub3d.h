/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:50:43 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/06 14:24:36 by rbroque          ###   ########.fr       */
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
# define NEWLINE			'\n'

////////////////
// STRUCTURES //
////////////////

struct s_map
{
	char	**matrix;
	size_t	height;
	size_t	width;
};

/////////////
// TYPEDEF //
/////////////

typedef struct s_map	t_map;

///////////////
// FUNCTIONS //
///////////////

//// map ////

	//// init_map

	// init_map.c

t_map	*init_map(const char *const lines);

	// init_matrix.c

char	**init_matrix(
			const size_t height,
			const size_t width,
			const char *const lines);

// free_map.c

void	free_map(t_map *const map);

//// read_file ////

// get_file.c

char	*get_file(const char *const file_name);

// is_file_valid.c

bool	is_file_valid(const char *const filename, const int fd);

#endif