# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 11:03:26 by anoukmourna       #+#    #+#              #
#    Updated: 2024/06/21 16:25:44 by anomourn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -lpthread

NAME = philo
NAME_BONUS = philo_bonus

FILES = ./Mandatory/philo.c \
		./Mandatory/utils.c \
		./Mandatory/pars.c \
		./Mandatory/test_thread.c \
		./Mandatory/test_mutex.c \
		./Mandatory/init.c	\
		./Mandatory/test_time.c

FILES_BONUS = ./bonus/philo_bonus.c \
		./bonus/utils_bonus.c \
		./bonus/pars_bonus.c \

OBJS = $(FILES:.c=.o)

OBJS_BONUS = $(FILES_BONUS:.c=.o)

RM = @rm -f

.SILENT: $(OBJS) $(OBJS_BONUS)

all: $(NAME)

$(NAME): $(OBJS)
		@echo "Compiling philo..."
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		@echo "Completed! 🤠"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
		@echo "Compiling philo bonus..."
		@$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)
		@echo "Completed! 🤠"

clean:
		@echo "Cleaning up..."
		$(RM) $(OBJS) $(OBJS_BONUS)
		@echo "Cleaned! 🧹"

fclean:
		@echo "Wait..."
		$(RM) $(OBJS) $(OBJS_BONUS)
		$(RM) $(NAME) $(NAME_BONUS)
		@echo "Cleaned! 🧹"

re: fclean all

.PHONY: all bonus clean fclean re



		

