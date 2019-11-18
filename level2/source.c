// gcc source.c -fno-stack-protector -z execstack
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	p(void) {
	void *old_eip;
	char buff[0x40];

	fflush(stdout);
	gets(buff);
	asm("mov 4(%ebp),%eax");
	asm("mov %eax, -0xc(%ebp)");
	if (((int)old_eip & 0xb0000000) == 0xb0000000) {
		printf("(%p)\n", (void *)old_eip);
		exit(1);
	}
	puts(buff);
	return ((int)strdup(buff));
}

int		main(int ac, char **av) 
{
	return (p());
}
