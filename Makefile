NAMESERVER = server
NAMECLIENT = client
LIB = ft_printf/libftprintf.a
SRCSERVER = server.c
SRCCLIENT = client.c
CFLAGS = -Wall -Wextra -Werror
CC = gcc
OBJSERVER = $(SRCSERVER:.c=.o)
OBJCLIENT = $(SRCCLIENT:.c=.o)

RM = rm -rf

all: $(LIB) $(NAMESERVER) $(NAMECLIENT)

$(LIB):
	make -C ./ft_printf

$(NAMESERVER) : $(OBJSERVER)
	$(CC) $(OBJSERVER) -o $(NAMESERVER) $(LIB)

$(NAMECLIENT) : $(OBJCLIENT)
	$(CC) $(OBJCLIENT) -o $(NAMECLIENT) $(LIB)


clean:
	@${RM} $(OBJSERVER) $(OBJCLIENT)
	@${MAKE} -C ./ft_printf fclean

fclean: clean
	rm -rf $(NAMESERVER) $(NAMECLIENT)
	rm -rf ./ft_printf/libftprintf.a

re:fclean all

.PHONY : re fclean clean all
