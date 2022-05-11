SRCFILES=	Wati-Main.c	\
			Wati-Parsing.c	\
			Wati-Display.c	\
			Wati-FlashMcqueen.c	\
			Wati-Load_img.c

HEADFILES= Wati_So_long.h Wati-Libft/libft.h mlx/mlx.h

LIBRARY		= -L Wati-Libft -lft -L mlx -lmlx

LIBFT_FILE	= Wati-Libft/libft.a

F= ${SRCFILES}

O= ${F:.c=.o}

OBJFILES= ${SRCFILES:.c=.o}

NAME= so_long

CC= gcc

all: lib ${NAME}

lib:
	make -C Wati-Libft

%.o:	%.c ${HEADFILES}
		${CC} -Wall -Wextra -Werror -Imlx -c $< -o $@

${NAME}:	${OBJFILES} ${LIBFT_FILE}
	${CC} -Wall -Wextra -Werror ${LIBRARY} $^ -framework OpenGL -framework AppKit -o ${NAME}
clean: 
	${RM} ${OBJFILES} ${O}

fclean: clean
	${RM} ${NAME}
	make fclean -C Wati-Libft
	

re: fclean all

        
.PHONY: all clean fclean re