NAME		=	fillit
CC			=	gcc
CFLAGS		+=	-Wall -Wextra -Werror -I headers/
OFLAGS		=	-c $(CFLAGS)


LIB_DIR		=	./lib/
LIB_LINKS	=	-lft
LINK_LIBS	=	-L $(LIB_DIR) $(LIB_LINKS)


MAIN		=	main.c
CFILES		=	read_create.c maps.c solve.c stack.c

OFILES		= $(CFILES:.c=.o)


all: $(NAME)


$(NAME): $(OFILES)
	$(MAKE) -C ./libft
	mkdir lib
	mv ./libft/libft.a ./lib/
	$(CC) $(CFLAGS) -o $(NAME) $(MAIN) $(OFILES) $(LINK_LIBS)

clean:
	/bin/rm -rf $(OFILES)
	$(MAKE) -C ./libft clean

fclean:
	/bin/rm -rf $(OFILES)
	$(MAKE) -C ./libft clean
	/bin/rm -rf ./lib/libft.a
	/bin/rm -rf ./lib
	/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean re fclean