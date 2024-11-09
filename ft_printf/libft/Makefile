# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelsetih <aelsetih@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 11:25:28 by aelsetih          #+#    #+#              #
#    Updated: 2024/05/10 12:15:04 by aelsetih         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGES = -Wall -Wextra -Werror
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_strmapi.c ft_striteri.c
SRCS_B = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS = ${SRCS:.c=.o}
OBJS_B = $(SRCS_B:.c=.o)
INCDIR = ./includes


all: $(NAME)

$(NAME): $(OBJS) $(OBJS_B)
	ar rcs $(NAME) $(OBJS) $(OBJS_B)
	
%.o: %.c
	cc $(CFLAGES) -I$(INCDIR) -c $< -o $@
	
bonus: $(OBJS) $(OBJS_B)
	ar rcs $(NAME) $(OBJS) $(OBJS_B)

%.o: %.c
	cc $(CFLAGES) -I$(INCDIR) -c $< -o $@
	
clean:
	rm -f $(OBJS) $(OBJS_B)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re bonus
