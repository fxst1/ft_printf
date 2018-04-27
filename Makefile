# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fxst1 <fxst1@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/12 10:57:23 by fxst1             #+#    #+#              #
#    Updated: 2018/04/27 01:06:28 by fxst1            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = cc
FLAGS = -Wall -Wextra -Werror -g
NAME = libftprintf.a
INC = -I inc/
LIBS =
OBJDIR = ./obj/

SRC := $(filter %.c, $(shell find src -type f))
OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))
all: $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJDIR)%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
	@rm -rf $(OBJDIR)

fclean:
	@rm -rf $(OBJDIR)
	@rm -rf $(NAME)

testlib:
	$(CC) $(FLAGS) $(INC) -o test test.c -L. -lftprintf

re: fclean all

push: fclean
	git add --all
	git commit -am "make push"
	git push
