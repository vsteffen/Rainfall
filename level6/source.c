// gcc source.c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void    n() {
	system("/bin/cat /home/user/level7/.pass");
}

void    m() {
	puts("Nope");
}


int main(int ac, char **av)
{
	void    *add1;
	void    **add2;

	add1 = malloc(0x40);
	add2 = malloc(0x4);

	*add2 = m;

	strcpy(add1, av[1]);

	((void (*)(void))*add2)();

	return(0);
}