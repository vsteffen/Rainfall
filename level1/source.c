// gcc source.c -fno-stack-protector -z execstack
#include <stdlib.h>
#include <stdio.h>

void	run() {
	fprintf(stderr, "Good... Wait what?\n");
	system("/bin/sh");
}

int		main(int ac, char **av) {
	char	buff[0x40];

	gets(buff);
	return (0);
}
