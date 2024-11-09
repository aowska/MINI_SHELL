NAME =			libftprintf.a
CC =			cc
CFLAGS =		-Wall -Wextra -Werror
SRCS =			ft_printf.c print_support.c
OBJS =			${SRCS:.c=.o}
LIBFT_SRCS =	$(wildcard libft/*.c)
LIBFT_OBJS =	$(LIBFT_SRCS:.c=.o)

all:	$(NAME)
$(NAME):	$(OBJS) libft/libft.a
	ar rcs $(NAME) $(OBJS) $(LIBFT_OBJS)
	
	
$(OBJS):	%.o:	%.c	libft/libft.h
	$(CC) $(CFLAGS) -c -o $@ $<

libft/libft.a: $(LIBFT_SRCS) libft/libft.h
	make -C libft
	
clean:
	make -C libft clean
	rm -f $(OBJS)
	
fclean:	clean
	make -C libft fclean
	rm -f $(NAME)
	
re:	fclean all

.PHONY: all clean fclean re
