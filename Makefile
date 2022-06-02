all:
	gcc -o main main.c get_next_line.c  get_next_line_utils.c -D BUFFER_SIZE=1 -g -Wall -Wextra -Werror #-fsanitize=address
	./main