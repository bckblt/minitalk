# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bakarabu <bakarabu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 18:32:20 by bakarabu          #+#    #+#              #
#    Updated: 2024/11/07 18:32:20 by bakarabu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a

SRCS	 	=	ft_printf.c

OBJS 		= $(SRCS:.c=.o)

CFLAGS 		= -Wall -Werror -Wextra

$(NAME):	$(OBJS)
			ar -rc $(NAME) $(OBJS) 

.o:			.c ft_printf.h
			gcc $(CFLAGS) -o $@ -c $<

all: 		$(NAME)

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re: 		fclean all

.PHONY:		all clean fclean re bonus