###############
#### SHELL ####
###############

SHELL		= /usr/bin/bash

##############
#### SRCS ####
##############

PATH_SRCS	+=	srcs/
PATH_SRCS	+=	srcs/config/
PATH_SRCS	+=	srcs/config/color/
PATH_SRCS	+=	srcs/math/
PATH_SRCS	+=	srcs/print/
PATH_SRCS	+=	srcs/read_file/
PATH_SRCS	+=	srcs/window/
PATH_SRCS	+=	srcs/window/data/
PATH_SRCS	+=	srcs/window/display/
PATH_SRCS	+=	srcs/window/display/draw/
PATH_SRCS	+=	srcs/window/display/line/
PATH_SRCS	+=	srcs/window/loop/
PATH_SRCS	+=	srcs/window/loop/events/
PATH_SRCS	+=	srcs/window/map/
PATH_SRCS	+=	srcs/window/map/init_map/
PATH_SRCS	+=	srcs/window/map/is_map_valid/
PATH_SRCS	+=	srcs/window/map/player/
PATH_SRCS	+=	srcs/window/map/raycast/

### srcs/

SRCS	 	+=	cub3d.c

### srcs/config/

SRCS		+=	is_rgb.c
SRCS		+=	attribute_utils.c
SRCS		+=	init_config.c
SRCS		+=	build_config.c
SRCS		+=	free_config.c
SRCS		+=	print_config.c
SRCS		+=	is_config_sequence_valid.c

### srcs/config/color/

SRCS	 	+=	get_color_from_rgb.c
SRCS	 	+=	set_color.c

### srcs/math/

SRCS		+=	conversion.c

### srcs/print/

SRCS		+=	print_format_error.c

### srcs/read_file/

SRCS	 	+=	get_file.c
SRCS		+=	is_file_valid.c

### srcs/window/

SRCS	 	+=	init_window.c
SRCS	 	+=	free_window.c
SRCS	 	+=	is_window_complete.c

### srcs/window/data/

SRCS	 	+=	init_data.c
SRCS	 	+=	free_data.c

### srcs/window/display/

SRCS	 	+=	display_window.c
SRCS	 	+=	display_map.c
SRCS	 	+=	display_minimap.c
SRCS	 	+=	display_minimap_utils.c
SRCS	 	+=	display_player.c

### srcs/window/display/draw

SRCS	 	+=	draw_on_map.c
SRCS	 	+=	draw_on_minimap.c
SRCS	 	+=	draw_square.c
SRCS	 	+=	draw_vertical.c
SRCS	 	+=	draw_vertical_utils.c
SRCS	 	+=	draw_tile.c
SRCS	 	+=	put_pixel.c

### srcs/window/display/line/

SRCS	 	+=	init_line.c
SRCS	 	+=	line_utils.c
SRCS	 	+=	put_line.c

### srcs/window/loop/

SRCS	 	+=	loop.c
SRCS	 	+=	keyboard.c

### srcs/window/loop/events/

SRCS	 	+=	e_close_window.c

### srcs/window/map/

SRCS	 	+=	free_map.c
SRCS	 	+=	print_map.c
SRCS	 	+=	tile_type.c

### srcs/window/map/init_map/

SRCS	 	+=	init_map.c
SRCS	 	+=	init_matrix.c

### srcs/window/map/is_map_valid/

SRCS		+=	is_map_valid.c
SRCS	 	+=	is_map_closed.c
SRCS	 	+=	is_map_closed_utils.c
SRCS		+=	is_map_content_valid.c
SRCS	 	+=	is_map_unique.c

### srcs/window/map/player/

SRCS	 	+=	get_player.c
SRCS	 	+=	set_pos.c

### srcs/window/map/raycast/

SRCS	 	+=	get_vect.c
SRCS	 	+=	dda.c
SRCS	 	+=	raycaster.c

vpath %.c $(PATH_SRCS)

##############
#### OBJS ####
##############

PATH_OBJS	+=	objs/
OBJS		+=	$(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

##################
#### INCLUDES ####
##################

INCLUDES	+=	-I includes/
INCLUDES	+=	-I $(LIBFT_FOLDER)/includes
INCLUDES	+=	-I $(MLX_FOLDER)
INCLUDES	+=	-I /usr/lib/
INCLUDES	+=	-I /usr/includes/

#################
#### HEADERS ####
#################

PATH_HEADERS +=	includes/

HEADERS		+=	cub3d.h

vpath %.h $(PATH_HEADERS)

###############
#### LIBFT ####
###############

LIBFT_FOLDER =	libft/
LIBFT		 =	$(LIBFT_FOLDER)/libft.a

#############
#### MLX ####
#############

MLX_FOLDER	=	minilibx-linux/
MLX			=	$(MLX_FOLDER)/libmlx_Linux.a
MLX_TAR		=	minilibx-linux.tgz
MLX_LINK	=	https://cdn.intra.42.fr/document/document/21463/$(MLX_TAR)

################
#### TESTER ####
################

### TESTER

TESTER_FOLDER	= tests/
TESTER			= $(TESTER_FOLDER)/tester.sh

### NORM

NORM			= $(TESTER_FOLDER)/norminette/norm.sh

### CUNIT

CUNIT_FOLDER	= $(TESTER_FOLDER)/CUNIT/
CUNIT			= $(CUNIT_FOLDER)/run_cunit.sh

### FUNCHECK

FUNCHECK_FOLDER			= $(TESTER_FOLDER)/funcheck_dir/
FUNCHECK_REPO			= $(FUNCHECK_FOLDER)/funcheck/
FUNCHECK_FOLDER_LIB		= $(FUNCHECK_REPO)/library/
FUNCHECK_FOLDER_HOST	= $(FUNCHECK_REPO)/host
FUNCHECK_SCRIPT			= $(FUNCHECK_FOLDER)/run_tests.sh

### VALGRIND

ifeq ($(valgrind), true)
	VALGRIND	+= valgrind
endif

###############
#### LINKS ####
###############

LINKS	+=	-lXext
LINKS	+=	-lX11
LINKS	+=	-lm
LINKS	+=	-lz

#####################
#### COMPILATION ####
#####################

CC			=	cc

CFLAGS		+=	-Wall
CFLAGS		+=	-Wextra
CFLAGS		+=	-g3

ifneq ($(no_error), true)
	CFLAGS		+=	-Werror
endif

ifeq ($(debug), true)
	CFLAGS	+= -fsanitize=address,undefined
endif

ifeq ($(print_debug), true)
	CFLAGS	+= -D PRINT_DEBUG=true
endif

ifeq ($(map), true)
	CFLAGS	+= -D MAP_DISPLAY=true
endif

ifeq ($(minimap), true)
	CFLAGS	+= -D MINIMAP_DISPLAY=true
endif

ifeq ($(filter test,$(MAKECMDGOALS)),test)
	CFLAGS	+= -D TEST=true
endif

##############
#### NAME ####
##############

NAME		+=	cub3d

#################
#### DISPLAY ####
#################

RED='\033[0;31m'
GREEN='\033[1;32m'
ORANGE='\033[0;33m'
YELLOW='\033[1;33m'
BLUE='\033[1;36m'
NC='\033[0m' # No Color

ifndef ECHO
T := $(words $(SRCS))
N := x
C = $(words $N)$(eval N := x $N)

ECHOC = echo -ne "\r\033[2K"
ECHO = $(ECHOC) $(ORANGE) "[`expr $C '*' 100 / $T`%]"
endif

###############

all 	:	$(MLX) $(LIBFT) $(NAME)

$(LIBFT):
	echo -e $(BLUE) "\n====> Building libft.a <===="$(NC)"\n"
	$(MAKE) -sC $(LIBFT_FOLDER)
	echo -e $(BLUE) "\n====> Building $(NAME) <===="$(NC)"\n"

$(MLX_TAR):
	echo -e $(BLUE) "\n====> Downloading MLX <===="$(NC)"\n"
	wget $(MLX_LINK) &> /dev/null
	tar -zxvf $(MLX_TAR) &> /dev/null
	$(ECHOC) $(GREEN) "--> MLX DOWNLOADED !"$(NC)"\n"

$(MLX): $(MLX_TAR)
	echo -e $(BLUE) "\n====> Building MLX <===="$(NC)"\n"
	$(MAKE) -sC $(MLX_FOLDER) &> /dev/null
	$(ECHOC) $(GREEN) "--> MLX COMPILED !"$(NC)"\n"

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(INCLUDES) $(LIBFT) $(MLX) $(LINKS)
	$(ECHOC) $(GREEN) "--> $(NAME) COMPILED !"$(NC)"\n\n"

$(OBJS) :	$(PATH_OBJS)/%.o: %.c Makefile $(HEADERS)
	$(ECHO) $(ORANGE) "Compiling $<"
	mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

run		: all
	$(ECHOC) $(GREEN) "RUNNING $(NAME)"$(NC)"\n\n"
	./$(NAME)

norm	:
	$(ECHOC) $(BLUE) "\n""NORM : "$(NC)""
	./$(NORM)

test	: all
	echo -e $(BLUE) "\n====> CUB3D TESTS"$(NC)"\n"
	$(MAKE) -sC $(CUNIT_FOLDER)
	$(CUNIT) $(VALGRIND)
	echo -e $(BLUE) "\n====> Building FUNCHECK TESTS <===="$(NC)"\n"
	$(MAKE) -sC $(FUNCHECK_FOLDER_LIB)
	$(MAKE) -sC $(FUNCHECK_FOLDER_HOST)
	$(FUNCHECK_SCRIPT)

cunit: all
	$(MAKE) -sC $(CUNIT_FOLDER)
	$(CUNIT) $(VALGRIND)
	
funcheck: all
	echo -e $(BLUE) "\n====> Building FUNCHECK TESTS <===="$(NC)"\n"
	$(MAKE) -sC $(FUNCHECK_FOLDER_LIB)
	$(MAKE) -sC $(FUNCHECK_FOLDER_HOST)
	$(FUNCHECK_SCRIPT)

clean	:
	$(RM) -r $(PATH_OBJS)
	$(MAKE) -sC $(LIBFT_FOLDER) clean > /dev/null
	$(MAKE) -sC $(CUNIT_FOLDER) clean > /dev/null
	$(MAKE) -sC $(FUNCHECK_FOLDER_LIB) clean > /dev/null
	$(MAKE) -sC $(FUNCHECK_FOLDER_HOST) clean > /dev/null
	$(ECHOC) $(GREEN) "--> .o files deleted !"$(NC)"\n"

fclean	:	clean
	$(ECHOC) $(YELLOW) "Cleaning up $(NAME)..." $(NC)
	$(MAKE) -sC $(LIBFT_FOLDER) fclean > /dev/null
	$(MAKE) -sC $(CUNIT_FOLDER) fclean > /dev/null
	$(MAKE) -sC $(FUNCHECK_FOLDER_LIB) fclean > /dev/null
	$(MAKE) -sC $(FUNCHECK_FOLDER_HOST) fclean > /dev/null
	$(RM) $(NAME)
	$(ECHOC) $(GREEN) "--> $(NAME) deleted !"$(NC)"\n"

re 		: fclean
	echo -e $(YELLOW) "\nRebuilding..." $(NC)
	$(MAKE) -s

.PHONY	: all run norm test clean fclean re
.SILENT	:
