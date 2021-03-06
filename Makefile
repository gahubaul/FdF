# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/05 03:18:25 by gahubaul          #+#    #+#              #
#    Updated: 2016/03/05 03:18:31 by gahubaul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf
FLAG=-lmlx -framework OpenGL -framework Appkit
FLAGN=-Wall -Wextra -Werror

SRC = 	srcs/fdf.c \
		srcs/fdf_color.c \
		srcs/fdf_image.c \
		srcs/fdf_key.c \
		srcs/fdf_modif.c \
		srcs/fdf_others.c \
		srcs/fdf_print.c \
		srcs/fdf_struct.c


all: $(NAME)
	@printf ""

$(NAME): $(SRC)
	@make -C libft
	@echo "\033[33;32m|\033[31m Compilation de la libft\t\t\033[33;32m | OK |"
	@gcc -o $(NAME) $(SRC) $(FLAG) $(FLAGN) libft/libft.a
	@echo "\033[33;32m|\033[31m Compilation du programme Fdf\t\t\033[33;32m | OK |"
	@echo "\033[33;31m-----------------------------------------------"
	@echo "\033[33;32m|\033[33;32m The \033[31mfdf \033[33;32mfile is create\t\t\033[33;32m | OK |"

clean:
	@echo "\033[33;32m|\033[33m Destruction des fichiers .o libf\t\033[33;32m | OK |"
	@make -C libft clean

fclean: clean
	@make -C libft fclean
	@echo "\033[33;32m|\033[33m Destruction du fichier  .a libft\t\033[33;32m | OK |"
	@rm -f $(NAME)
	@echo "\033[33;32m|\033[33m Destruction de l'executable fdf\t\033[33;32m | OK |"

line:
	@echo "\033[33;31m-----------------------------------------------"

re: fclean line all

.PHONY: all line fclean clean re
