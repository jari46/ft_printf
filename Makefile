# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yehan <yehan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 18:17:00 by yehan             #+#    #+#              #
#    Updated: 2022/03/24 11:01:58 by yehan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libftprintf.a

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
AR			:= ar
ARFLAGS		:= -rcs
RM			:= rm -f

LIBFTDIR	:= ./libft
PRINTFDIR	:= ./ft_printf

SRCS		:= \
			ft_printf.c \
			ft_printf_utils.c

#OBJS	= $(join $(addprefix $(PRINTFDIR)/,$(dir $(SRCS))), $(notdir $(SRCS:.c=.o)))
_SRCS		= $(addprefix ./ft_printf/, $(SRCS))
OBJS		= $(_SRCS:.c=.o)

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
		cp $(LIBFTDIR)/libft.a $@
		$(AR) $(ARFLAGS) $@ $^