# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Mainfile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snorcros <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/13 15:41:13 by snorcros          #+#    #+#              #
#    Updated: 2019/10/27 14:49:40 by snorcros         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = out 
SRC := main.c srcs/*.c
OBJ := $(patsubst %.c, %.o, $(SRC))
INClUDES := includes/*.h

LIB_FLAG := -L libft/ -lft

all: $(NAME)

%.o : src/%.c $(INCLUDES)
	@gcc -c $(CFLAGS) -I $(INCLUDES) $< -o $@
	@echo $(patsubst src/%.c, %, $<)

$(NAME): $(OBJ)
	@make -C libft
	@gcc -o $(NAME) -Wall -Wextra -Werror $(LIB_FLAG) $(OBJ)
	@echo "DONE"

clean:
	@rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean $(NAME)

.PHONY: all clean fclean re
