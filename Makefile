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
SRCS := srcs/*.c
OBJS := *.o
INClUDES := includes
CFLAGS = -Wall -Wextra -Werror
LIB_FLAG := -L libft/ -lft

all: $(NAME)

$(NAME): lib $(OBJS)
	gcc $(CFLAGS) -o $(NAME) $(OBJS) -L libft -lft

$(OBJS):
	gcc $(CFLAGS) -c $(SRCS) -I includes/ -I libft/includes/

lib:
	make -C libft

clean:
	@rm -f $(OBJS)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean $(NAME)

.PHONY: all clean fclean re
