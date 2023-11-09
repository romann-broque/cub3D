/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_defines.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:06:20 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/09 14:38:44 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_DEFINES_H
# define CUB3D_DEFINES_H

# ifndef PRINT_DEBUG
#  define PRINT_DEBUG		0
# endif

# ifndef TEST
#  define TEST				0
# endif

# define WINDOW_WIDTH		1200
# define WINDOW_HEIGHT		800
# define WINDOW_TITLE		"cub3D"
# define BRIGHTNESS_FACTOR	0.7
# define BRIGHTNESS_POWER	0.7
# define PLAYER_XOFFSET		0.5
# define PLAYER_YOFFSET		0.5
# define SPRITE_XOFFSET		0.5
# define SPRITE_YOFFSET		0.5
# define MINIMAP_XOFFSET	25
# define MINIMAP_YOFFSET	25
# define MAP_XOFFSET		25
# define MAP_YOFFSET		200
# define MINIMAP_RADIUS		5
# define TILE_SIZE			15
# define DOOR_WIDTH			3
# define DOOR_RADIUS		2
# define DOOR_TIME			50
# define WAIT_DOOR_TIME		150
# define PLAYER_SIZE		4
# define SPRITE_SIZE		2
# define FOV				80
# define STEP_SIZE			0.001
# define MOVE_SPEED			0.1
# define ROTATE_SPEED		7
# define MOUSE_ROTATE_COEFF	0.3

// NUMBERS

# define EXPECTED_ARG_COUNT			2
# define INVALID_FD					-1
# define COUNT_LINE_ERROR			-1
# define INVALID_OFFSET				-1
# define ATTRIBUTE_SUCCESS			0
# define ATTRIBUTE_FAILURE			1
# define ATTRIBUTE_DUPLICATED		2
# define INVALID_OFFSET				-1
# define RGB_SIZE					3
# define BITS_PER_BYTE				8
# define FPS_FREQUENCY				10
# define KEY_COUNT					9
# define MANDATORY_ATTRIBUTE_COUNT	6
# define SPECIAL_TILE_COUNT			10

# ifdef BONUS
#  define TEXTURE_COUNT		15
#  define ATTRIBUTE_COUNT	15
# else
#  define TEXTURE_COUNT		4
#  define ATTRIBUTE_COUNT	6
# endif

// CHAR

# define NEWLINE			'\n'
# define WALL				'1'
# define DOOR_HOR			'D'
# define DOOR_VERT			'd'
# define BLANK				' '
# define RGB_SEPARATOR		','

// STRINGS

# define FILE_EXTENSION		".cub"
# define VALID_CHAR_DIR		"NSWE"
# define GROUND				"0NSWE"
# define NORTH_KEY			"NO"
# define SOUTH_KEY			"SO"
# define WEST_KEY			"WE"
# define EAST_KEY			"EA"
# define FLOOR_KEY			"F"
# define CEIL_KEY			"C"
# define DOOR_KEY			"D"
# define SP1_KEY			"2"
# define SP2_KEY			"3"
# define SP3_KEY			"4"
# define SP4_KEY			"5"
# define SP5_KEY			"6"
# define SP6_KEY			"7"
# define SP7_KEY			"8"
# define SP8_KEY			"9"
# define SPRITES			"23456789"
# define SPECIAL_TILES		"Dd23456789"

# ifdef BONUS
#  define VALID_CHAR			"0123456789Dd NSWE\n"
# else
#  define VALID_CHAR			"01 NSWE\n"
# endif

// Errors

# define ERROR_USAGE				"Usage: ./cub3d <file.cub>"
# define MLX_ERROR					"MLX_ERROR"
# define EMPTY_FILE					"EMPTY FILE"
# define MAP_NOT_CLOSED				"MAP NOT CLOSED"
# define MAP_NOT_UNIQUE				"MAP NOT UNIQUE"
# define MAP_TOO_BIG				"MAP TOO BIG"
# define MAP_CONTENT_WRONG			"MAP CONTENT IS WRONG"
# define DOOR_NOT_SURROUNDED		"DOOR NOT SURROUNDED"
# define UNKNOWN_CONFIG				"UNKNOWN CONFIG"
# define DUPLICATED_CONFIG			"DUPLICATED CONFIG"
# define WRONG_RGB					"WRONG RGB"
# define INVALID_FILENAME			"FILENAME IS INVALID"
# define INVALID_TEXTURE			"INVALID TEXTURE"
# define SPECIAL_TEXTURE_NOT_SET	"SPECIAL TEXTURE NOT SET"

// Warning

# define DIMENSIONS_NOT_SUPPORTED	"Dimensions not supported"

// Warning

# define DIMENSIONS_NOT_SUPPORTED	"Dimensions not supported"

// Print Colors

# define NC					"\033[0m"
# define RED_PRINT			"\033[0;31m"
# define GREEN_PRINT		"\033[0;32m"
# define ORANGE_PRINT		"\033[0;33m"

// Pixel Colors

# define BLACK				0x000000
# define WHITE				0xffffff
# define RED				0xff0000
# define BLUE				0x0000ff
# define GREEN				0x00ff00
# define MAGENTA			0xff00ff

// Key

# define K_LEFT				0xff51
# define K_RIGHT			0xff53
# define K_W				0x0077
# define K_S				0x0073
# define K_A				0x0061
# define K_D				0x0064
# define K_M				0x006d
# define K_SPACE			0x0020
# define K_ESC				0xff1b
# define NO_KEY				0

// Cursor

# define LEFT_CLICK			1

# ifndef BONUS
#  define BONUS 0
# endif

#endif
