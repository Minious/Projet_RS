#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"
#include "header_posix_ustar.h"

int main(int argc, char **argv) {
	struct header_posix_ustar ma_struct;
	int fd = open("test.tar", O_RDONLY);
	read(fd, &ma_struct, 512);

	printf("%s\n", ma_struct.name);

	return 0;
}