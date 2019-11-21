// gcc source.c -fno-stack-protector -z execstack
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int m = 0;

void o() {
	system("/bin/sh");
	_exit(1);
}

int	n(void) {
	char buff[0x200];

	fgets(buff, 0x200, stdin);
	printf(buff);
	exit(1);
}

int		main(int ac, char **av) 
{
	return (n());
}