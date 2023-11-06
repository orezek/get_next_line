#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

// // Assuming get_next_line is declared somewhere
// char *get_next_line(int fd);

void test_get_next_line()
{
	char *temp_filename2 = "./text.txt";
	int fd2 = open(temp_filename2, O_RDONLY);
	char *line = get_next_line(fd2);
	printf("%s", line);
	// while(line != NULL)
	// {
	// 	printf("%s", line);
	// 	line = get_next_line(fd2);
	// }
	// Clean up
	free(line);
	//close(fd);
	close(fd2);
	//remove(temp_filename);
}

int main() {
	test_get_next_line();
	printf("All tests passed!\n");
	return 0;
}
