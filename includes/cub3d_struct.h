/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:08:41 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/26 16:10:22 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

# include "cub3d.h"

////////////
/// ENUM ///
////////////

enum e_attribute_type
{
	E_NORTH,
	E_SOUTH,
	E_WEST,
	E_EAST,
	E_FLOOR,
	E_CEIL
};

typedef enum e_side
{
	NORTH_FACE,
	SOUTH_FACE,
	WEST_FACE,
	EAST_FACE
}		t_side;

enum e_mod
{
	E_STD,
	E_MAP,
};

////////////////
// STRUCTURES //
////////////////

typedef struct s_data
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

typedef struct s_texture
{
	t_data	data;
	int		height;
	int		width;
	double	step;
	double	tex_pos;
}		t_texture;

typedef struct s_config
{
	char		*attribute_array[ATTRIBUTE_COUNT + 1];
	int			ceil_color;
	int			floor_color;
	t_texture	textures[TEXTURE_COUNT];
}		t_config;

typedef struct s_tile
{
	char	tile_char;
	bool	is_marked;
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
	t_vect	ray;
	t_vect	step;
	t_pos	hitpoint;
	double	coeff;
	t_side	side;
}		t_cast;

typedef struct s_map
{
	t_tile		**matrix;
	size_t		height;
	size_t		width;
	t_player	player;
}		t_map;

typedef struct s_key
{
	int		key_value;
	bool	pressure;
}		t_key;

typedef struct s_win
{
	t_config	config;
	void		*mlx_ptr;
	void		*win_ptr;
	t_data		data;
	t_map		*map;
	enum e_mod	mod;
	t_key		*keys;
}		t_win;

typedef struct s_event_mapping
{
	t_key	key;
	int		(*event)(t_win *const);

}		t_event_mapping;

#endif 