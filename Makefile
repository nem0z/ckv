SRC	=	main.c ckv/ckv.c ckv/kvpair/kvpair.c ckv/linkedlist/linkedlist.c ckv/hashmap/hashmap.c

CFLAGS	=	-Iinclude -W -Wall -Wextra

OBJ	=	$(SRC:.c=.o)

NAME	=	bin.o

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:	fclean all