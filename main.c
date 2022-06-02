#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int fd;
	char *line;

	fd = open("test", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	// line = get_next_line(fd);
	// printf("%s\n", line);
	// free(line);
	close(fd);

	// char *strr1 = "Hello";
	// char *strr2 = "World";
	//  printf("|%s|", ft_substr(str, ft_strchr(str, '\n')));
	//  printf("|%s|", ft_substr(ft_strchr(str, '\n'), NULL));
	//  char *str1 = malloc(ft_strlen(strr1) + 1);
	//  char *str2 = malloc(ft_strlen(strr2) + 1);
	//  strcpy(str1, strr1);
	//  strcpy(str2, strr2);
	//  printf("|%s|%s|\n", strr1, strr2);
	//  printf("|%s|\n", ft_strjoin(str1, str2));
	//  printf("|%s|\n", ft_strjoin(NULL, str2));
	//  printf("|%s|\n", ft_strjoin(str1, NULL));

	system("leaks main");
	return (0);
}
