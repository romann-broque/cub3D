
###############
#### SHELL ####
###############

SHELL		= /usr/bin/bash

##############
#### SRCS ####
##############

PATH_SRCS	+=	srcs/
PATH_SRCS	+=	srcs/tests/
PATH_SRCS	+=	srcs/utils/

### srcs/

SRCS	 	+=	cub3d.test.c

### srcs/tests/

SRCS	 	+=	is_rgb.test.c
SRCS	 	+=	is_map_unique.test.c
SRCS	 	+=	is_map_closed.test.c
SRCS		+=	is_map_content_valid.test.c
SRCS		+=	is_config_sequence_valid.test.c

### srcs/utils/

SRCS	 	+=	test_utils.test.c
SRCS	 	+=	list_test.test.c
SRCS	 	+=	get_map_from_file.test.c

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
INCLUDES	+=	-I ../../includes/
INCLUDES	+=	-I $(LIBFT_FOLDER)/includes
INCLUDES	+=	-I $(MLX_FOLDER)

#################
#### HEADERS ####
#################

PATH_HEADERS +=	../../includes/
PATH_HEADERS +=	includes/

HEADERS		+=	cub3d.h
HEADERS		+=	cunit.test.h

vpath %.h $(PATH_HEADERS)

###############
#### LIBFT ####
###############

LIBFT_FOLDER	=	../../libft/
LIBFT			=	$(LIBFT_FOLDER)/libft.a

MLX_FOLDER		=	../../minilibx-linux/
MLX				=	$(MLX_FOLDER)/libmlx_Linux.a

LIB			+= $(LIBFT)
LIB			+= $(MLX)

###################
#### CUB3D_LIB ####
###################

CUB3D_OBJS_ALL	=	$(wildcard ../../objs/*.o)
CUB3D_OBJS		:=	$(filter-out ../../objs/cub3d.o,$(CUB3D_OBJS_ALL))
CUB3D_LIB		=	libcub3d.a

###############
#### LINKS ####
###############

LINKS += -lcunit
LINKS += -lm

#####################
#### COMPILATION ####
#####################

CC			=	cc
CFLAGS		+=	-Wall
CFLAGS		+=	-Wextra

ifneq ($(no_error), true)
	CFLAGS		+=	-Werror
endif
ifeq ($(debug), true)
	CFLAGS	+= -fsanitize=address,undefined -g3
endif

##############
#### NAME ####
##############

NAME		+=	cunit

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
#### RULES ####
###############

all 	:	$(CUB3D_LIB) $(NAME)

$(CUB3D_LIB): $(CUB3D_OBJS)
	ar rcs $@ $^
#	$(ECHOC) $(GREEN) "--> $(CUB3D_LIB) COMPILED !"$(NC)"\n"
	echo -e $(BLUE) "\n====> Building CUNIT TESTS <===="$(NC)"\n"

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBFT) $(CUB3D_LIB) $(LIBFT) $(LINKS)
#	$(ECHOC) $(GREEN) "--> $(NAME) COMPILED !"$(NC)"\n\n"

$(OBJS) :	$(PATH_OBJS)/%.o: %.c Makefile $(HEADERS)
#	$(ECHO) $(ORANGE) "Compiling $<"
	mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean	:
	$(RM) -r $(PATH_OBJS)
	$(MAKE) -sC $(LIBFT_FOLDER) clean > /dev/null
#	$(ECHOC) $(GREEN) "--> .o files deleted !"$(NC)"\n"

fclean	:	clean
#	$(ECHOC) $(YELLOW) "Cleaning up $(NAME)..." $(NC)
	$(MAKE) -sC $(LIBFT_FOLDER) fclean > /dev/null
	$(RM) $(NAME)
#	$(ECHOC) $(GREEN) "--> $(NAME) deleted !"$(NC)"\n"
	$(RM) $(CUB3D_LIB)
#	$(ECHOC) $(GREEN) "--> $(CUB3D_LIB) deleted !"$(NC)"\n"

re 		: fclean
	echo -e $(YELLOW) "\nRebuilding..." $(NC)
	$(MAKE) -s

.PHONY	: all clean fclean re
.SILENT	: all clean fclean re $(NAME) $(OBJS) $(CUB3D_LIB)
