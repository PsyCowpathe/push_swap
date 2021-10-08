# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agirona <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/09 02:21:08 by agirona           #+#    #+#              #
#    Updated: 2021/10/08 17:19:26 by agirona          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = push_swap.c swap_instruction.c stack_utils.c parsing.c stack_finder.c \
	   magic_sort.c stack_init.c utility.c instruction.c delete_stack.c \
	   mini_sort.c TMP_debug.c

SRCS_DIR = src

OBJS = $(SRCS:.c=.o)

OBJS_DIR = obj

OBJS_PATH = $(addprefix $(OBJS_DIR)/, $(OBJS))

INC	= include

LIBRARY = libft/libft.a

CFLAGS	= -Wall -Wextra -Werror -I $(INC)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INC)/push_swap.h $(LIBRARY)
	gcc $(CFLAGS) -c $< -o $@

all: create_obj_dir lib $(NAME)

lib:
			make -C ./libft

$(NAME) :	$(OBJS_PATH)
			gcc $(OBJS_PATH) $(LIBRARY) -o $(NAME)

create_obj_dir :
			rm -f obj || true
			mkdir -p obj

clean:
			rm -f $(OBJS_PATH)
			make -C ./libft clean

fclean:		clean
			rm -f $(NAME)
			rm -rf obj
			make -C ./libft fclean

re:			fclean all

.PHONY:		all lib create_obj_dir clean fclean re
