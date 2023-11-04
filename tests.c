#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

// // Assuming get_next_line is declared somewhere
// char *get_next_line(int fd);

void test_get_next_line() {
    // Create a temporary file
    char temp_filename[] = "/tmp/testfileXXXXXX";
    int fd = mkstemp(temp_filename);
    if (fd < 0) {
        perror("Failed to open file");
        return;
	}

	// Write some lines to the file
	//char *lines[] = {"1\n", "Line 2\n", "Line 3\n", "Line 444 444 sdfsdf44\n", "Line 5\n", "\n"};
	char *lines[] = {"1jlsfj;alsfjas;lfjasl;dkfjsdklfjsfdfjslkdfjasl;dfjas;ldfjasdl;fkjdasf;ladsjfl;asjfslfjdkfjdkfjdkfjffdfsfasdfalsjfs;lfjas;lfjsl;dfjsdlfjasfl;"};
	//char *lines[] = {"Line 1\n", "Line 2\n", "Line 3\n", "Line 444 444 sdfsdf44\n", "Line 5\n", "\n", "", "   ", "\n\n\n\n\n"};
	for (int i = 0; i < sizeof(lines) / sizeof(char*); i++) {
		write(fd, lines[i], strlen(lines[i]));
	}

	// Reset the file descriptor to the beginning of the file
	lseek(fd, 0, SEEK_SET);

	// Test get_next_line
	for (int i = 0; i < sizeof(lines) / sizeof(char*); i++) {
		char *line = get_next_line(fd);
		printf("%s", line);
		assert(line != NULL);
		assert(strcmp(line, lines[i]) == 0);
		free(line);
	}

	// Clean up
	close(fd);
	remove(temp_filename);
}

int main() {
	test_get_next_line();
	printf("All tests passed!\n");
	return 0;
}
