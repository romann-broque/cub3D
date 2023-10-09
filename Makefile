###############
#### SHELL ####
###############

SHELL		= /usr/bin/bash

##############
#### SRCS ####
##############

PATH_SRCS	+=	srcs/
PATH_SRCS	+=	srcs/map/
PATH_SRCS	+=	srcs/map/init_map/
PATH_SRCS	+=	srcs/map/is_map_valid/
PATH_SRCS	+=	srcs/read_file/

### srcs/

SRCS	 	+=	cub3d.c

### srcs/map/

SRCS	 	+=	free_map.c
SRCS	 	+=	print_map.c

### srcs/map/init_map/

SRCS	 	+=	init_map.c
SRCS	 	+=	init_matrix.c

### srcs/map/is_map_valid/

SRCS	 	+=	is_map_closed.c
SRCS	 	+=	is_map_closed_utils.c

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

###############
#### LINKS ####
###############

LINKS += -lreadline

################
#### TESTER ####
################

### TESTER

TESTER_FOLDER	= tests/
TESTER			= $(TESTER_FOLDER)/tester.sh

### NORM

NORM			= $(TESTER_FOLDER)/norminette/norm.sh

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
	$(CC) $(CFLAGS) $^ -o $@ $(LIBFT) $(LINKS)
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

test	:
	$(MAKE) -s
	echo -e $(BLUE) "\n====> MINISHELL TESTS"$(NC)"\n"
	$(TESTER) $(VALGRIND)

clean	:
	$(RM) -r $(PATH_OBJS)
	$(MAKE) -sC $(LIBFT_FOLDER) clean > /dev/null
	$(ECHOC) $(GREEN) "--> .o files deleted !"$(NC)"\n"

fclean	:	clean
	# $(ECHOC) $(YELLOW) "Cleaning up $(NAME)..." $(NC)
	$(MAKE) -sC $(LIBFT_FOLDER) fclean > /dev/null
	$(RM) $(NAME)
	$(ECHOC) $(GREEN) "--> $(NAME) deleted !"$(NC)"\n"

re 		: fclean
	echo -e $(YELLOW) "\nRebuilding..." $(NC)
	$(MAKE) -s

.PHONY	: all run norm test clean fclean re
.SILENT	:
