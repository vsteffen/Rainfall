// gcc source.c -fno-stack-protector
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int m = 0;

int	v(void) {
	char buff[0x200];

	fgets(buff, 0x200, stdin);
	printf(buff);
	if (m == 0x40) {
		fprintf(stdout, "Wait what?!\n");
		system("/bin/sh");
	}
	return (m);
}

int		main(int ac, char **av) 
{
	return (v());
}
