/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:50:43 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/09 09:08:38 by rbroque          ###   ########.fr       */
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

# ifndef PRINT_DEBUG
#  define PRINT_DEBUG		0
# endif

# define EXPECTED_ARG_COUNT	2
# define INVALID_FD			-1
# define FILE_EXTENSION		".cub"
# define NEWLINE			'\n'
# define WALL				'1'
# define GROUND				"0NSWE"

// Errors

# define MAP_NOT_CLOSED		"MAP NOT CLOSED"

// Colors

# define NC					"\033[0m"
# define RED				"\033[0;31m"
# define GREEN				"\033[0;32m"

////////////////
// STRUCTURES //
////////////////

typedef struct s_tile
{
	char	tile_char;
	bool	is_marked;
}		t_tile;

typedef struct s_map
{
	t_tile	**matrix;
	size_t	height;
	size_t	width;
}		t_map;

///////////////
// FUNCTIONS //
///////////////

//// print ////

// print_format_error.c

void	print_format_error(const char *const error_message);

//// map ////

	//// init_map

	// init_map.c

t_map	*init_map(const char *const lines);

	// init_matrix.c

t_tile	**init_matrix(
			const size_t height,
			const size_t width,
			const char *const lines);

	//// is_map_valid

	// is_map_closed.c

bool	is_map_closed(t_map *const map);

	// is_map_closed_utils.c

bool	is_inside_map(
			const t_map *const map,
			const ssize_t x, const ssize_t y);
bool	is_wall(
			const t_map *const map,
			const size_t x, const size_t y);
bool	is_marked(
			const t_map *const map,
			const size_t x, const size_t y);
void	mark_as_viewed(
			t_map *const map,
			const size_t x, const size_t y);

// free_map.c

void	free_tile_matrix(t_tile **const matrix, const size_t size);
void	free_map(t_map *const map);

// print_map.c

void	print_map(const t_map *const map);

//// read_file ////

// get_file.c

char	*get_file(const char *const file_name);

// is_file_valid.c

bool	is_file_valid(const char *const filename, const int fd);

#endif