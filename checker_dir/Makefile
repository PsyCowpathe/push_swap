# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agirona <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 17:43:47 by agirona           #+#    #+#              #
#    Updated: 2021/10/18 19:21:24 by agirona          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = ../checker

SRCS = checker.c delete_stack.c parsing.c stack_init.c swap_instruction.c \
	   utility.c

SRCS_DIR = src

OBJS = $(SRCS:.c=.o)

OBJS_DIR = obj

OBJS_PATH = $(addprefix $(OBJS_DIR)/, $(OBJS))

INC = ../include

LIBRARY = ../libft/libft.a

CFLAGS = -Wall -Wextra -Werror -I $(INC)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INC)/checker.h $(LIBRARY)
	gcc $(CFLAGS) -c $< -o $@

all: create_obj_dir lib $(NAME)

lib:
			make -C ../libft

$(NAME) :	$(OBJS_PATH)
			gcc $(OBJS_PATH) $(LIBRARY) -o $(NAME)

create_obj_dir :
			rm -f obj || true
			mkdir -p obj

clean:
			rm -f $(OBJS_PATH)
			make -C ../libft clean

fclean:
			rm -f $(OBJS_PATH)
			rm -f $(NAME)
			rm -rf obj
			make -C ../libft fclean

re:			fclean all

.PHONY:		all lib create_obj_dir clean fclean re
