#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

//cc test_cases.c get_next_line.c  get_next_line_utils.c && ./a.out

void test_get_next_line()
{
	char *temp_filename2 = "./text.txt";
	int fd2 = open(temp_filename2, O_RDONLY);
	char *line;
	line = get_next_line(fd2);
	while(line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd2);
	}

	close(fd2);
}

int main() {
	test_get_next_line();
	printf("All tests passed!\n");
	return 0;
}
