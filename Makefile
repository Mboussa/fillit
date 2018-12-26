# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/02 12:55:54 by moboussa     #+#   ##    ##    #+#        #
#    Updated: 2018/11/26 15:51:04 by moboussa    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #
NAME = fillit

SRC = $(wildcard *.c)

FLAGS = -Wall -Wextra -Werror

OBJ= $(SRC:.c=.o)

all: 	$(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C libft
	gcc -I includes -o $@ $^ libft/libft.a $(FLAGS)

%.o: %.c
	gcc -I includes -o $@ -c $< $(FLAGS)

clean:
	$(MAKE) clean -C libft
	rm -f $(OBJ)

fclean: clean
	rm -rf libft/libft.a
	rm -f $(NAME)

re: fclean all