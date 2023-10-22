/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:50:43 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/22 21:50:44 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

///////////////////////////////////////////////////////////////////////////////
//									INCLUDES								 //
///////////////////////////////////////////////////////////////////////////////

# include "libft.h"
# include "mlx.h"
# include <X11/Xlib.h>
# include <limits.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

///////////////////////////////////////////////////////////////////////////////
//									DEFINES									 //
///////////////////////////////////////////////////////////////////////////////

# ifndef PRINT_DEBUG
#  define PRINT_DEBUG		0
# endif

# ifndef TEST
#  define TEST				0
# endif

# ifndef MINIMAP_DISPLAY
#  define MINIMAP_DISPLAY	0
# endif

# ifndef MAP_DISPLAY
#  define MAP_DISPLAY		0
# endif

# define EXPECTED_ARG_COUNT	2
# define INVALID_FD			-1
# define COUNT_LINE_ERROR	-1
# define INVALID_OFFSET		-1
# define RGB_SIZE			3
# define ATTRIBUTE_COUNT	6
# define WINDOW_WIDTH		1600
# define WINDOW_HEIGHT		900
# define WINDOW_TITLE		"cub3D"
# define PLAYER_XOFFSET		0.5
# define PLAYER_YOFFSET		0.5
# define MINIMAP_XOFFSET	25
# define MINIMAP_YOFFSET	25
# define MAP_XOFFSET		25
# define MAP_YOFFSET		200
# define MINIMAP_RADIUS		3
# define TILE_SIZE			15
# define PLAYER_SIZE		4
# define MAX_LEN_RAY		10
# define FOV				90

// CHAR

# define NEWLINE			'\n'
# define WALL				'1'
# define BLANK				' '
# define RGB_SEPARATOR		','

// STRINGS

# define FILE_EXTENSION		".cub"
# define VALID_CHAR			"01 NSWE\n"
# define VALID_CHAR_DIR		"NSWE"
# define GROUND				"0NSWE"
# define NORTH_KEY			"NO"
# define SOUTH_KEY			"SO"
# define WEST_KEY			"WE"
# define EAST_KEY			"EA"
# define FLOOR_KEY			"F"
# define CEIL_KEY			"C"

// Errors

# define MAP_NOT_CLOSED		"MAP NOT CLOSED"
# define MAP_NOT_UNIQUE		"MAP NOT UNIQUE"
# define MAP_TOO_BIG		"MAP TOO BIG"
# define MAP_CONTENT_WRONG	"MAP CONTENT IS WRONG"
# define UNKNOWN_CONFIG		"UNKNOWN CONFIG"
# define DUPLICATED_CONFIG	"DUPLICATED CONFIG"
# define WRONG_RGB			"WRONG RGB"
# define INVALID_FILENAME	"FILENAME IS INVALID"

// Print Colors

# define NC					"\033[0m"
# define RED_PRINT			"\033[0;31m"
# define GREEN_PRINT		"\033[0;32m"

// Pixel Colors

# define BLACK				0x000000
# define WHITE				0xffffff
# define RED				0xff0000
# define BLUE				0x0000ff
# define GREEN				0x00ff00

// Key

# define K_ESC				0xff1b
# define NO_KEY				0

///////////
// ENUM //
///////////

enum e_attribute_type
{
	E_NORTH,
	E_SOUTH,
	E_WEST,
	E_EAST,
	E_FLOOR,
	E_CEIL
};

////////////////
// STRUCTURES //
////////////////

typedef struct s_config
{
	char	*attribute_array[ATTRIBUTE_COUNT + 1];
}		t_config;

typedef struct s_tile
{
	char	tile_char;
	bool	is_marked;
	bool	is_viewed;
}		t_tile;

typedef struct s_pos
{
	double	x;
	double	y;
}		t_pos;

typedef t_pos	t_vect;

typedef struct s_line
{
	t_pos	pos1;
	t_pos	pos2;
	t_pos	min_pos;
	t_pos	max_pos;
	long	dx;
	int		sx;
	long	dy;
	int		sy;
	long	error;
	long	e2;
	size_t	nb_points;
}		t_line;

typedef struct s_player
{
	t_pos	pos;
	t_vect	dir;
	t_vect	plane;

}		t_player;

typedef struct s_cast
{
	t_vect	dist;
	t_vect	step;
	t_pos	hitpoint;
	double	coeff;
	int		side;
}		t_cast;

typedef struct s_map
{
	t_tile		**matrix;
	size_t		height;
	size_t		width;
	t_player	player;
}		t_map;

typedef struct s_data
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

typedef struct s_win
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_data			data;
	t_map			*map;
	const t_config	*config;
}		t_win;

typedef struct s_event_mapping
{
	int	key;
	int	(*event)(t_win *const);

}		t_event_mapping;

///////////////////////////////////////////////////////////////////////////////
//									FUNCTIONS								 //
///////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////
/////			  config			/////
/////////////////////////////////////////

// is_rgb.c

bool		is_rgb(const char *const str);

// attribute_utils.c

int			build_attribute_from_sequence(
				t_config *const config, char *const *const sequence);

// init_config.c

void		init_config(t_config *const config);

// build_config.c

ssize_t		build_config(t_config *const config, char *const *const lines);

// free_config.c

void		free_config(t_config *const config);

// print_config.c

void		print_config(t_config *const config);

// is_config_sequence_valid.c

bool		is_sequence_valid(char *const *const sequence);

/////////////////////////////////////////
/////			  math				/////
/////////////////////////////////////////

// conversion.c

double		convert_deg_to_rad(const double degrees);
double		convert_rad_to_deg(const double radian);

/////////////////////////////////////////
/////			  print				/////
/////////////////////////////////////////

// print_format_error.c

void		print_format_error(const char *const error_message);

/////////////////////////////////////////
/////			 read_file			/////
/////////////////////////////////////////

// get_file.c

char		**get_file(const char *const file_name);

// is_file_valid.c

bool		is_file_valid(const char *const filename, const int fd);

/////////////////////////////////////////
/////			 window				/////
/////////////////////////////////////////

// init_window.c

void		init_window(t_win *const window,
				t_map *const map, const t_config *const config);

// free_window.c

void		free_window(t_win *const window);

// is_window_complete.c

bool		is_window_complete(t_win *const window);

	/////////////////////////////////////////
	/////			 display			/////
	/////////////////////////////////////////

	// display_window.c

void		display_window(t_win *const window);

	// display_map.c

void		display_map(t_win *const window);

	// display_minimap.c

void		display_minimap(t_win *const window);

	// display_player.c

void		display_player_on_map(t_win *const window);
void		display_player_on_minimap(t_win *const window);

	// draw_on_map.c

void		draw_square_on_map(t_win *const window,
				const t_pos pos, const size_t size,
				const int color);
void		draw_pos_on_map(t_win *const window,
				const t_pos pos, const int color);
void		draw_coordinate_on_map(t_win *const window,
				const double x, const double y,
				const int color);
void		draw_line_on_map(t_win *const window,
				const t_pos pos1, const t_pos pos2,
				const int color);

	// draw_on_minimap.c

void		draw_square_on_minimap(t_win *const window,
				const t_pos pos, const size_t size,
				const int color);
void		draw_pos_on_minimap(t_win *const window,
				const t_pos pos, const int color);
void		draw_coordinate_on_minimap(t_win *const window,
				const double x, const double y,
				const int color);
void		draw_line_on_minimap(t_win *const window,
				const t_pos pos1, const t_pos pos2,
				const int color);

	// draw_tile.c

void		draw_tile(t_win *const window,
				const t_pos pos,
				const size_t x, const size_t y);

	// put_pixel.c

void		put_pixel(t_data *data, const int x, const int y, const int color);

		/////////////////////////////////////////
		/////			line				/////
		/////////////////////////////////////////

		// init_line.c

void		init_line(t_line *line, const t_pos pos3, const t_pos pos2);
void		init_line_in_minimap(t_line *line,
				const t_pos pos1, const t_pos pos2);

		// line_utils.c

bool		is_line_printable(t_line *line);
bool		are_crd_same(const double c1, const double c2);
bool		are_pos_same(const t_pos pos1, const t_pos pos2);

		// put_line.c

void		put_line(t_data *data,
				const t_pos pos1, const t_pos pos2, const int color);
void		put_line_in_minimap(t_data *data,
				const t_pos pos1, const t_pos pos2, const int color);

	/////////////////////////////////////////
	/////			 loop				/////
	/////////////////////////////////////////

	// loop.c

void		loop(t_win *const window);

	// keyboard.c

int			key_press(const int key, t_win *window);

		/////////////////////////////////////////
		/////			events				/////
		/////////////////////////////////////////

		// e_close_window.c

int			close_window(t_win *const ptr);

	/////////////////////////////////////////
	/////			data				/////
	/////////////////////////////////////////

	// init_data.c

void		init_data(void *const mlx_ptr, t_data *const dest);

	// free_data.c

void		free_data(const t_data *data, void *const mlx_ptr);

	/////////////////////////////////////////
	/////			 	map				/////
	/////////////////////////////////////////

	// free_map.c

void		free_tile_matrix(t_tile **const matrix, const size_t size);
void		free_map(t_map *const map);

	// print_map.c

void		print_map(const t_map *const map);

	// tile_type.c

bool		is_blank(
				const t_map *const map,
				const size_t x, const size_t y);
bool		is_wall(
				const t_map *const map,
				const size_t x, const size_t y);

bool		is_ground(
				const t_map *const map,
				const size_t x, const size_t y);

bool		is_player(const t_map *const map,
				const size_t x, const size_t y);

		/////////////////////////
		////     init_map    ////
		/////////////////////////

		// init_map.c

t_map		*init_map(char *const *const lines);

		// init_matrix.c

t_tile		**init_matrix(
				const size_t height,
				const size_t width,
				char *const *const lines);

		/////////////////////////
		////   is_map_valid  ////
		/////////////////////////

		// is_map_closed.c

bool		is_map_closed(const t_map *const map);

		// is_map_closed_utils.c

bool		is_closed_dfs(const t_map *const map,
				const ssize_t x, const ssize_t y);

		// is_map_content_valid.c

bool		is_map_content_valid(const t_map *const map);

		// is_map_unique.c

bool		is_map_unique(const t_map *const map);

		// is_map_valid.c

bool		is_map_valid(t_map *const map);

		/////////////////////////
		////	player		 ////
		/////////////////////////

		// get_player.c

t_player	get_player(t_map *const map);

		// set_pos.c

void		set_pos(t_pos *const pos,
				const double x, const double y);
void		set_vect(t_vect *const vect,
				const double x, const double y);

		/////////////////////////
		////	raycast		 ////
		/////////////////////////

		// raycaster.c

void		raycaster(t_win *const window);

		// get_vect.c

t_vect		get_ray(const t_player player, const size_t x);
t_vect		get_delta_dist(const t_vect ray);
t_vect		get_step_from_ray(const t_vect ray);
t_vect		get_side_dist(
				const t_pos pos, const t_vect ray,
				const t_vect delta_dist);

		// dda.c

t_cast		dda(t_map *const map, const t_pos pos,
				const t_vect ray, const t_vect delta_dist);

#endif