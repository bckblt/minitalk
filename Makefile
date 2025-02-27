NAME = minitalk
SERVER = server
CLIENT = client
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
PRINTF_LIB = ./ft_printf/libftprintf.a

$(NAME): all

all:
	make -C ./ft_printf
	$(CC) $(CFLAGS) ./src/server.c $(PRINTF_LIB) -o $(SERVER)
	$(CC) $(CFLAGS) ./src/client.c $(PRINTF_LIB) -o $(CLIENT)


$(LIB):
	make -C ./ft_printf

$(NAMESERVER) : $(OBJSERVER)
	$(CC) $(OBJSERVER) -o $(NAMESERVER) $(LIB)

$(NAMECLIENT) : $(OBJCLIENT)
	$(CC) $(OBJCLIENT) -o $(NAMECLIENT) $(LIB)


clean:
	make clean -C ./ft_printf

fclean:
	make fclean -C ./ft_printf
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

bonus: fclean
	make -C ./ft_printf
	$(CC) $(CFLAGS) ./bonus_src/server_bonus.c $(PRINTF_LIB) -o $(SERVER)
	$(CC) $(CFLAGS) ./bonus_src/client_bonus.c $(PRINTF_LIB) -o $(CLIENT)

.PHONY : re fclean clean all bonus
