# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yehan <yehan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 18:17:00 by yehan             #+#    #+#              #
#    Updated: 2022/03/23 18:18:24 by yehan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libftprintf.a

LIBFTDIR	:= ./libft
LIBFT		:= libft.a

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
AR			:= ar
ARFLAGS		:= -rcs
RM			:= rm -f

SRCS		:= \
			ft_printf.c

OBJS	= $(SRCS:.c=.o)

.PHONY:		all clean fclean re bonus

all:	$(NAME)

clean:
			make clean -C $(LIBFTDIR)
			$(RM) $(OBJS)

fclean:		clean
			make fclean -C $(LIBFTDIR)
			$(RM) $(NAME)

re:			fclean all

$(NAME): $(OBJS)
		make bonus -C $(LIBFTDIR)
		cp $(LIBFTDIR)/$(LIBFT) $@
		$(AR) $(ARFLAGS) $@ $^