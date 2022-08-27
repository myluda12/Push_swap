# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 17:55:36 by ayajrhou          #+#    #+#              #
#    Updated: 2021/09/28 17:55:38 by ayajrhou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = ft_atoi.c ft_base_function.c ft_itoa.c ft_libft_func.c ft_radix_sort.c ft_sort_nums.c ft_sorting_indexing.c push_swap.c \

OBJS = $(SRCS:.c=.o)

FLAGS = -Werror -Wextra -Wall

ASAN = -g -fsanitize=address

$(NAME) :
	gcc -g $(SRCS) -o $(NAME)
	
all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(NAME) $(OBJS)


re: fclean all
 .PHONY : all clean fclean re
bounus:
