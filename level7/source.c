// gcc source.c
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

char c[80];

void m() {
	printf("%s - %d\n", c, (int)time(NULL));
}

int main(int ac, char **av) {
	int	*v1;
	int	*v2;
	FILE	*file;

	v1 = malloc(8);
	*v1 = 1;
	v1[1] = (int)malloc(8);
	v2 = malloc(8);
	*v2 = 2;
	v2[1] = (int)malloc(8);

	strcpy((char *)v1[1], (char *)(av[1]));
	strcpy((char *)v2[1], (char *)(av[2]));

	file = fopen("/home/user/level7/level7", "r");
//	file = fopen("/home/user/level8/.pass", "r");
	fgets(c, 0x44, file);

	puts("~~");
	return (0);
}
