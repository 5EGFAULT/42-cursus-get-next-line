
#include "get_next_line.h"
#include <fcntl.h> 
#include <stdio.h>
int	main(void)
{
	int f = open("./f",O_RDONLY);

	// char d[BUFFER_SIZE + 1];
	// read(f, d, BUFFER_SIZE);
	// printf("|{%s}|",d);
	// printf("\n|{%d}|",d[1]);

	printf("|%d|\n",BUFFER_SIZE);
	char  *s; 
	s = get_next_line(f);
	printf("|%s|",s);
	 free(s);	s = get_next_line(f);
	printf("|%s|",s);
	 free(s);	s = get_next_line(f);
	printf("|%s|",s);
	 free(s);	s = get_next_line(f);
	printf("|%s|",s);
	 free(s);	s = get_next_line(f);
	printf("|%s|",s);
	//  system("leaks test");
	 free(s);
	close(f);
	return 0;
}