NAME	=	cub3d

CC		=	cc

CFLAGS	=	 -Wall -Wextra -Werror -Iincludes -Imlx 

MLX = -lmlx -framework OpenGL -framework Appkit

RM		=	-rm -f

SOURCE	=	$(wildcard *.c)

OBJECT	=	$(SOURCE:.c=.o)

%.o:%.c
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJECT)
			$(CC) $(CFLAGS) $(MLX) $(OBJECT) -o $(NAME)

clean:
			$(RM) $(OBJECT)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

