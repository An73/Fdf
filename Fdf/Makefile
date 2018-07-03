NAME = fdf

LBMK = make -C libft/ fclean && make -C libft/

SRCS = main.c get_next_line.c entry_point.c mlx_place.c deal_key.c draw.c rotate.c

GCCO = gcc -Wall -Wextra -Werror -c $(SRCS) -Ifdf.h
GCC = gcc -Wall -Wextra -Werror *.o ./libft/libft.a -lmlx -framework OpenGL -framework AppKit -o fdf

all: $(NAME)

$(NAME): $(SRCS) fdf.h
	$(LBMK)
	$(GCCO)
	$(GCC)
clean:
	/bin/rm -f *.o
	make clean -C libft

fclean: clean
	/bin/rm -f fdf
	make fclean -C libft

re: fclean all