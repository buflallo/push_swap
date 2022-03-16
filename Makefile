SRC =	instructions.c Push_swap.c big_sort.c big_sortt.c \
		utils.c error.c mini_sort.c utils2.c utils3.c shortcut.c

OBJ =	instructions.o Push_swap.o big_sort.o big_sortt.o \
		utils.o error.o mini_sort.o utils2.o utils3.o shortcut.o

CC = gcc -c

NAME = push_swap.a

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(SRC)
	ar rc $(NAME) $(OBJ)

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all