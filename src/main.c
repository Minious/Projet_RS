#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "header_posix_ustar.h"

int main(int argc, char **argv) {
	struct header_posix_ustar ma_struct;
	read(fd, &ma_struct, 512);

	return 0;
}