SRC =	instructions.c Push_swap.c BigSort.c BigSortt.c \
		utils.c error.c MiniSort.c utils2.c utils3.c shortcut.c

OBJ =	instructions.o Push_swap.o BigSort.o BigSortt.o \
		utils.o error.o MiniSort.o utils2.o utils3.o shortcut.o

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