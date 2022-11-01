# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 17:48:29 by eminatch          #+#    #+#              #
#    Updated: 2022/11/01 13:52:03 by eminatch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC_PATH	= src/
OBJ_PATH	= obj/
LIB		= -L./LIBFT -lft 

CC = clang
CFLAGS = -Wall -Wextra -Werror -g -MMD -MP
SRC = pipex.c \
	pipex_utils.c \
	error_field.c \
	
SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
DEPS	= $(addprefix ${OBJ_PATH}, ${SRC:.c=.d})
INCS	= -I./includes/

RM = rm -rf

all: $(NAME)

$(NAME) : $(OBJS)
	@$(MAKE) --no-print-directory header
	@echo "Compiling LIBFT objects ⚡\n"
	@$(MAKE) --no-print-directory -C ./LIBFT
	@echo "\nCompiling PIPEX objects ⚡\n"
	@$(CC) $(CFLAGS) $(OBJS) ${LIB} -o $(NAME)
	@echo "\nCompiled PIPEX 🍀\n"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c 
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) ${INCS} -o $@ -c $<

clean:
	@$(MAKE) --no-print-directory fclean -C ./LIBFT
	@echo "\nCleaning PIPEX objects 🧹\n"
	@${RM} $(OBJ_PATH) ${DEPS}
	@echo "\nClean Pipex ✨\n"

fclean: clean
	@${RM} $(NAME)

re: fclean all

define HEADER
___    _  ___    ___    _    _            __     ___           _  _   _  _____  _____  ___    _   _ 
(  _`\ (_)(  _`\ (  _`\ ( )  ( )          /  )   (  _`\ /'\_/`\(_)( ) ( )(  _  )(_   _)(  _`\ ( ) ( )
| |_) )| || |_) )| (_(_)`\`\/'/'        /' /'    | (_(_)|     || || `\| || (_) |  | |  | ( (_)| |_| |
| ,__/'| || ,__/'|  _)_   >  <        /' /'      |  _)_ | (_) || || , ` ||  _  |  | |  | |  _ |  _  |
| |    | || |    | (_( ) /'/\`\     /' /'        | (_( )| | | || || |`\ || | | |  | |  | (_( )| | | |
(_)    (_)(_)    (____/'(_)  (_)   (_/'          (____/'(_) (_)(_)(_) (_)(_) (_)  (_)  (____/'(_) (_)                                                                                                                                                                                                                                                                                                                                                                                                    
                                                                                                      
endef
export HEADER

header :
	clear
	@echo "$$HEADER"

-include ${DEPS}

.SECONDARY : ${OBJ} ${OBJ_PATH} ${OBJS}

.PHONY : all clean fclean re