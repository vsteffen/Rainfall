// gcc source.c -fno-stack-protector -z execstack
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int m = 0;

void p(char *buff) {
	printf(buff);
}

int	n(void) {
	char buff[0x200];

	fgets(buff, 0x200, stdin);
	p(buff);
	if (m == 0x1025544)
		system("/bin/sh");
	return (m);
}

int		main(int ac, char **av) 
{
	return (n());
}