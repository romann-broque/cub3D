###############
#### SHELL ####
###############

SHELL		= /usr/bin/bash

##############
#### SRCS ####
##############

PATH_SRCS	+=	srcs/
PATH_SRCS	+=	srcs/config/
PATH_SRCS	+=	srcs/print/
PATH_SRCS	+=	srcs/map/
PATH_SRCS	+=	srcs/map/init_map/
PATH_SRCS	+=	srcs/map/is_map_valid/
PATH_SRCS	+=	srcs/read_file/

### srcs/

SRCS	 	+=	cub3d.c

### srcs/config/

SRCS		+= attribute_utils.c
SRCS		+= init_config.c
SRCS		+= build_config.c
SRCS		+= free_config.c
SRCS		+= print_config.c

### srcs/print/

SRCS		+=	print_format_error.c

### srcs/map/

SRCS	 	+=	free_map.c
SRCS	 	+=	print_map.c

### srcs/map/init_map/

SRCS	 	+=	init_map.c
SRCS	 	+=	init_matrix.c

### srcs/map/is_map_valid/

SRCS		+=	is_map_valid.c
SRCS	 	+=	is_map_closed.c
SRCS	 	+=	is_map_closed_utils.c
SRCS		+=	is_map_content_valid.c
SRCS	 	+=	is_map_unique.c

### srcs/read_file/

SRCS	 	+=	get_file.c
SRCS		+=	is_file_valid.c

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

all 	:	$(LIBFT) $(NAME)

$(LIBFT):
	echo -e $(BLUE) "\n====> Building libft.a <===="$(NC)"\n"
	$(MAKE) -sC $(LIBFT_FOLDER)
	echo -e $(BLUE) "\n====> Building $(NAME) <===="$(NC)"\n"

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBFT)
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
