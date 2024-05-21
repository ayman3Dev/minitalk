NAME = server

CLIENT = client

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC_NAME = server.c  ft_putdec.c ft_putchar.c

SRC_CLIENT = client.c ft_atoi.c

OBJ = $(SRC_NAME:.c=.o)

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

all: $(NAME) $(CLIENT)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ)  -o $(NAME)

$(CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(CLIENT)

%.o: %.c minitalk.h
		 $(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJ) $(OBJ_CLIENT)

fclean: clean
		$(RM) $(NAME) $(CLIENT)

re: fclean all
