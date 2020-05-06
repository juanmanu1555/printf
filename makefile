
NAME = libftprintf.a

SRCS = printf_regex.c printf_utils.c printf_validations.c printf.c

OBJ = $(subst .c,.o,$(SRC))

CFLAGS = -Wall -Wextra -Werror

.c.o:
		cc ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJ}
			cd libft && ${MAKE}
			cp libft/libft.a ${NAME}
			ar rc ${NAME} ${OBJ}
			ranlib ${NAME}

# $(NAME):
		# gcc $(CFLAGS) -c $(SRC)
		# ar -rcs $(NAME) $(OBJ)
		# ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ) 
	${MAKE} clean -C ./libft

fclean: clean
		rm -f $(NAME)
		rm -f libft.all
		${MAKE} fclean -C ./libft

re: fclean all

.PHONY: clean fclean all re bonus