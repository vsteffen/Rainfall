#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main(int ac, char **av) {
	FILE *fd;
	char buff[0x84];

	fd = fopen("/home/user/end/.pass", "r");
	memset(buff, 0, 0x84);
	if (fd) {
		if (ac != 2)
			return(-1);
		else {
			fread(buff, 1, 0x42, fd);
			*(buff + sizeof(buff) / 2 - 1) = 0;
			buff[atoi(av[1])] = 0;
			fread(&buff[0x42], 1, 0x41, fd);
			fclose(fd);
			if (strcmp(buff, av[1]) == 0)
				execl("/bin/sh", "sh", NULL);
			else
				puts(buff + 0x42);
		}
	}
	return (0);
}
