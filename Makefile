# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thifranc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/04 19:24:34 by thifranc          #+#    #+#              #
#    Updated: 2016/03/24 13:47:40 by thifranc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = do_nb do_wrd get_char printf get_arg get_opt

SRCS:= $(addsuffix .c, $(SRCS))
SRCS:= $(addprefix ft_, $(SRCS))
OBJ = $(SRCS:%.c=%.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRCS)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@$(RM) $(OBJ)
	@echo "erasing all binary files"

fclean: clean
	@$(RM) $(NAME)
	@echo "erasing $(NAME)"

re: fclean all
	@echo "fclean + all"

.PHONY: all clean fclean re
