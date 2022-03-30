# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yehan <yehan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 18:17:00 by yehan             #+#    #+#              #
#    Updated: 2022/03/28 16:57:17 by yehan            ###   ########.fr        #
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

# 폴더 안에 들어있으므로 경로를 덧붙여준다.
OBJS		= $(addprefix $(PRINTFDIR)/,$(notdir $(SRCS:.c=.o)))

.PHONY:		all clean fclean re bonus

all:		$(NAME)

clean:
			make clean --directory=$(LIBFTDIR)
			$(RM) $(OBJS)

fclean:		clean
			make fclean --directory=$(LIBFTDIR)
			$(RM) $(NAME)

re:			fclean all

# repository
#      ㄴMakefile
#      ㄴft_printf/
#      ㄴlibft/
#         ㄴMakefile
# 1. libft/에서 make 명령어를 실행한다.
# 2. 거기 생긴 libft.a 파일을 현재 폴더에 libftprintf.a 라는 이름으로 가져온다.
# 3. libftprintf.a에 printf/의 .o파일들을 더해준다.

$(NAME): $(OBJS)
		make bonus --directory=$(LIBFTDIR)
		cp $(LIBFTDIR)/libft.a $(NAME)
		$(AR) $(ARFLAGS) $(NAME) $(OBJS)