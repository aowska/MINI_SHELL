NAME = mini_shell

src = src/main.c src/fd_echo.c src/resirect_append.c src/init_var.c src/fft_split.c src/handle_input.c src/ft_pwd.c \
		src/parsing.c src/free.c src/fd_ls.c src/resirect_output.c src/resirect_input.c src/get_next_line_utils.c \
		src/get_next_line.c src/fd_cat.c src/fd_variable.c src/heredoc.c

SRCS = $(src)
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

PRINTF= ft_printf/libftprintf.a

all: $(NAME)

$(PRINTF):
	make -C ft_printf/
	
$(NAME): $(OBJS) $(PRINTF)
	cc $(CFLAGS) $(OBJS) $(PRINTF) -lreadline -o $(NAME)
	
%.o: %.c
	cc $(CFLAGS) -c $< -o $@
clean:
	make -C ft_printf/ clean
	rm -f $(OBJS)

fclean: clean
	make -C ft_printf/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
