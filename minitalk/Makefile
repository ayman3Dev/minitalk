SERVER = server
CLIENT = client

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = server.c  ft_putdec.c ft_putchar.c

OBJ = $(SRC:.c=.o)

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ)  -o $(SERVER)

$(CLIENT): client.o ft_atoi.o
	$(CC) $(CFLAGS) client.o ft_atoi.o  -o $(CLIENT)

%.o: %.c minitalk.h
		 $(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJ) client.o ft_atoi.o

fclean: clean
		$(RM) $(SERVER) $(CLIENT)

re: fclean all
