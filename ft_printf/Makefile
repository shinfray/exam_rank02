# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 16:37:12 by shinfray          #+#    #+#              #
#    Updated: 2023/01/19 10:15:20 by shinfray         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS:= 	ft_printf.c \
		ft_printf_flags.c \
		ft_printf_hexa.c
OBJS:=	${SRCS:%.c=%.o}
NAME:= 	libftprintf.a
CFLAGS:= -Wall -Wextra -Werror
CPPFLAGS:= -MMD -MP
ARFLAGS:= crs
RM:=	rm -rf
DEPS:=	${OBJS:.o=.d}

all:		${NAME}

${NAME}:	${NAME}(${OBJS})

clean:
			${RM} ${OBJS} ${DEPS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

-include ${DEPS}
