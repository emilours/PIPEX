# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 17:48:29 by eminatch          #+#    #+#              #
#    Updated: 2022/09/14 17:57:26 by eminatch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex.a

CC = clang

SRC = pipex.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJ)
	ar rc pipex.a $(OBJ)

all : $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re