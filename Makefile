
NAME		:= libgnl.a
SRC	:= get_next_line_utils.c get_next_line.c
OBJ := $(patsubst %.c, %.o, $(SRC))
FLAGS		:= -Wall -Wextra -Werror
.PHONY		:  all clean fclean re


all:
	gcc $(FLAGS)  -fsanitize=leak   -D BUFFER_SIZE=42 main.c $(SRC) -I. -o test
#	gcc $(FLAGS) -fsanitize=address  -D BUFFER_SIZE=4 main.c $(SRC) -I. -o test
	./test
clean:
	rm -f test
# all: $(NAME)

# $(NAME): $(OBJ)

# %.o:%.c
# 	echo $@
# 	gcc $(FLAGS) -c -I. $<
# 	ar -rc $(NAME) $@
# clean:
# 	rm -f $(OBJ)
# fclean: clean
# 	rm -f $(NAME)
# re: fclean all
# test: $(NAME)
# 	gcc $(FLAGS)  -D BUFFER_SIZE=4 main.c $(NAME)  -I. -o test
# 	./test
