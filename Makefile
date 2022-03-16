SRC =	instructions.c Push_swap.c big_sort.c big_sortt.c \
		utils.c error.c mini_sort.c utils2.c utils3.c shortcut.c get_next_line.c  get_next_line_utils.c

OBJ =	instructions.o Push_swap.o big_sort.o big_sortt.o \
		utils.o error.o mini_sort.o utils2.o utils3.o shortcut.o get_next_line.o  get_next_line_utils.o

BN_SRC = checker.c
BN_OBJ = instructions.o big_sort.o big_sortt.o \
		utils.o error.o mini_sort.o utils2.o utils3.o shortcut.o get_next_line.o  get_next_line_utils.o checker.o

CC = gcc -c

NAME = push_swap.a
BONUS = checker.a

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(SRC)
	ar rc $(NAME) $(OBJ)

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME) $(BONUS)

bonus: $(BONUS)

$(BONUS) : $(BN_OBJ)
	$(CC) $(BN_SRC)
	ar rc $(BONUS) $(BN_OBJ)

re : fclean all