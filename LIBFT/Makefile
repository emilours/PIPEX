# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 19:42:17 by eminatch          #+#    #+#              #
#    Updated: 2022/10/11 21:00:52 by eminatch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_PATH    = src/
OBJ_PATH    = obj/

CC = clang
CFLAGS = -Wall -Wextra -Werror -g3 -MMD -MP

SRC = ft_isalpha.c \
      ft_isdigit.c \
      ft_isalnum.c \
      ft_isascii.c \
      ft_isprint.c \
      ft_strlen.c \
      ft_memset.c \
      ft_bzero.c \
      ft_memcpy.c \
      ft_memmove.c \
      ft_strlcpy.c \
      ft_strlcat.c \
      ft_toupper.c \
      ft_tolower.c \
      ft_strchr.c \
      ft_strrchr.c \
      ft_strncmp.c \
      ft_memchr.c \
      ft_memcmp.c \
      ft_strnstr.c \
      ft_atoi.c \
      ft_calloc.c \
      ft_strdup.c \
      ft_substr.c \
      ft_strjoin.c \
      ft_strtrim.c \
      ft_itoa.c \
      ft_strmapi.c \
      ft_split.c \
      ft_striteri.c \
      ft_putchar_fd.c \
      ft_putstr_fd.c \
      ft_putendl_fd.c \
      ft_putnbr_fd.c \

SRCS  = $(addprefix $(SRC_PATH), $(SRC))
OBJ   = $(SRC:.c=.o)
OBJS  = $(addprefix $(OBJ_PATH), $(OBJ))
DEPS  = $(addprefix ${OBJ_PATH}, ${SRC:.c=.d})
INCS  = -I./includes/

RM = rm -rf

all: $(NAME)

$(NAME) : $(OBJS)
	@ar rc $(NAME) $^
	@echo "\nCompiled LIBFT 🍀\n"	

$(OBJ_PATH)%.o: $(SRC_PATH)%.c 
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) ${INCS} -o $@ -c $<

clean: 
	@echo "\nCleaning LIBFT objects 🧹\n"
	@${RM} $(OBJ_PATH) ${DEPS}
	@echo "\nClean LIBFT ✨\n"

fclean: clean
	@${RM} $(NAME)
	
re: fclean all

-include ${DEPS}

.PHONY :  all clean fclean re