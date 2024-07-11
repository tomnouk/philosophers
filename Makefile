# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 11:03:26 by anoukmourna       #+#    #+#              #
#    Updated: 2024/07/11 11:12:24 by anomourn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -pthread -Wall -Wextra -Werror -g

NAME = philo

FILES = ./Mandatory/philo.c \
		./Mandatory/utils.c \
		./Mandatory/create_philo.c \
		./Mandatory/init_all.c	\
		./Mandatory/time.c \
		./Mandatory/death.c \
		./Mandatory/pars.c \

OBJS = $(FILES:.c=.o)

RM = rm -f

.SILENT: $(OBJS)

all: $(NAME)

$(NAME): $(OBJS)
		@echo "\e[0;35m$< ----> $@\e[0;m"
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		@echo "\e[0;32mCompleted! 🤠\e[0;m"

clean:
		@echo "Cleaning up..."
		$(RM) $(OBJS)
		@echo "\e[0;31mCleaned! 🧹\e[0;m"

fclean:
		@echo "\e[0;32mWait ...\e[0;m"
		$(RM) $(OBJS)
		$(RM) $(NAME)
		@echo "\e[0;32mCleaned! 🧹\e[0;m"

re: fclean all

.PHONY: all clean fclean re



		

