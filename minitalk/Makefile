NAME_S = server
NAME_C = client

SRC_S = server.c 
SRC_C = client.c \
		ft_atoi.c 

OBJ_S = $(SRC_S:.c=.o)
OBJ_C = $(SRC_C:.c=.o)

FTPRINTF := lib_printf/

FLAG = -Wall -Werror -Wextra
CC = gcc

%.o: %.c
	${CC} $(FLAG) -c $< -o $@

all: $(NAME_S) $(NAME_C)

$(NAME_S): $(OBJ_S) 
	make -C $(FTPRINTF)
	$(CC) $(FLAG) $(OBJ_S) lib_printf/libftprintf.a -o $(NAME_S)
$(NAME_C): $(OBJ_C)
	$(CC) $(FLAG) $(OBJ_C) lib_printf/libftprintf.a -o $(NAME_C)


clean: 
	make clean -C $(FTPRINTF)
	rm -f $(OBJ_S)
	rm -f $(OBJ_C)
	
fclean:	clean
	make fclean -C $(FTPRINTF)
	rm -f $(NAME_S)
	rm -f $(NAME_C)

re:	fclean all clean
