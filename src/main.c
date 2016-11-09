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

	printf("name %s\n", ma_struct.name);
	printf("mode %s\n", ma_struct.mode);
	printf("uid %s\n", ma_struct.uid);
	printf("gid %s\n", ma_struct.gid);
	printf("size %s\n", ma_struct.size);
	printf("mtime %s\n", ma_struct.mtime);
	printf("checksum %s\n", ma_struct.checksum);
	printf("typeflag %s\n", ma_struct.typeflag);
	printf("linkname %s\n", ma_struct.linkname);
	printf("magic %s\n", ma_struct.magic);
	printf("version %s\n", ma_struct.version);
	printf("uname %s\n", ma_struct.uname);
	printf("gname %s\n", ma_struct.gname);
	printf("devmajor %s\n", ma_struct.devmajor);
	printf("devminor %s\n", ma_struct.devminor);
	printf("prefix %s\n", ma_struct.prefix);
	printf("pad %s\n", ma_struct.pad);

	return 0;
}