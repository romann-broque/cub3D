/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jess <jess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:50:43 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/13 11:36:06 by jess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

///////////////////////////////////////////////////////////////////////////////
//									INCLUDES								 //
///////////////////////////////////////////////////////////////////////////////

# include "libft.h"
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

///////////////////////////////////////////////////////////////////////////////
//									DEFINES									 //
///////////////////////////////////////////////////////////////////////////////

# ifndef PRINT_DEBUG
#  define PRINT_DEBUG		0
# endif

# define EXPECTED_ARG_COUNT	2
# define INVALID_FD			-1
# define COUNT_LINE_ERROR	-1
# define FILE_EXTENSION		".cub"
# define VALID_CHAR			"01 NWES\n"
# define VALID_CHAR_DIR		"NWES"
# define NEWLINE			'\n'
# define WALL				'1'
# define BLANK				' '
# define GROUND				"0NSWE"
# define NORTH_KEY			"NO"
# define SOUTH_KEY			"SO"
# define WEST_KEY			"WE"
# define EAST_KEY			"EA"
# define FLOOR_KEY			"F"
# define CEIL_KEY			"C"
# define ATTRIBUTE_COUNT 	6
# define UNKNOWN_CONFIG		"UNKNOWN_CONFIG"

enum attributes
{
	NO,
	SO,
	WE,
	EA,
	F,
	C
};

// Errors

# define MAP_NOT_CLOSED		"MAP NOT CLOSED"
# define MAP_NOT_UNIQUE		"MAP NOT UNIQUE"
# define MAP_CONTENT_WRONG	"MAP CONTENT IS WRONG"

// Colors

# define NC					"\033[0m"
# define RED				"\033[0;31m"
# define GREEN				"\033[0;32m"

///////////////////////////////////////////////////////////////////////////////
//									STRUCTURES								 //
///////////////////////////////////////////////////////////////////////////////


enum e_attribute_type
{
	E_NORTH,
	E_SOUTH,
	E_WEST,
	E_EAST,
	E_FLOOR,
	E_CEIL
};

typedef struct s_config
{
	char	*attribute_array[ATTRIBUTE_COUNT + 1];
}		t_config;

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

///////////////////////////////////////////////////////////////////////////////
//									FUNCTIONS								 //
///////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////
/////			  print				/////
/////////////////////////////////////////

// print_format_error.c

void	print_format_error(const char *const error_message);

/////////////////////////////////////////
/////			  config			/////
/////////////////////////////////////////

	/////////////////////////
	////	init_config	 ////
	/////////////////////////

	// init_config.c

t_config	*init_config(char *const *const content);

	/////////////////////////
	//// is_config_valid ////
	/////////////////////////

	// is_sequence_valid.c

bool	is_sequence_valid(char *const *const sequence);

/////////////////////////////////////////
/////			 	map				/////
/////////////////////////////////////////

	/////////////////////////
	////     init_map    ////
	/////////////////////////

		// init_map.c

t_map	*init_map(char *const *const lines);

		// init_matrix.c

t_tile	**init_matrix(
			const size_t height,
			const size_t width,
			char *const *const lines);

	/////////////////////////
	////   is_map_valid  ////
	/////////////////////////

		// is_map_closed.c

bool	is_map_closed(const t_map *const map);

		// is_map_closed_utils.c

bool	is_inside_map(
			const t_map *const map,
			const ssize_t x, const ssize_t y);
bool	is_blank(
			const t_map *const map,
			const size_t x, const size_t y);
bool	is_wall(
			const t_map *const map,
			const size_t x, const size_t y);
bool	is_marked(
			const t_map *const map,
			const size_t x, const size_t y);
void	mark_as_viewed(
			const t_map *const map,
			const size_t x, const size_t y);

		// is_map_content_valid.c

bool	is_map_content_valid(const t_map *const map);

		// is_map_unique.c

bool	is_map_unique(const t_map *const map);

		// is_map_valid.c

bool	is_map_valid(t_map *const map);

// free_map.c

void	free_tile_matrix(t_tile **const matrix, const size_t size);
void	free_map(t_map *const map);

// print_map.c

void	print_map(const t_map *const map);

/////////////////////////////////////////
/////			 read_file			/////
/////////////////////////////////////////

// get_file.c

char	**get_file(const char *const file_name);

// is_file_valid.c

bool	is_file_valid(const char *const filename, const int fd);

#endif