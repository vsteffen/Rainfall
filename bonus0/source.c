#include <string.h>

char  *p(char *buff, char *str) {
	char buff_read[0x1000];

	puts(str);
	read(0, buff_read, 0x1000);
	*((char *)(strchr(buff_read, '\n'))) = 0;
	return (strncpy(buff, buff_read, 0x14));
}

void pp(char *buff) {
	char	buff1[0x14];
	char	buff2[0x14];
	char    space[4] = " ";
	
	p(buff2, " - ");
	p(buff1, " - ");
	strcpy(buff, buff2);
	*((char *)(strchr(buff, '\0'))) = space[0];
	strcat(buff, buff1);
}

int main(int ac, char **av) {
	char buff[0x2a];
	
	pp(buff);
	puts(buff);
	return (0);
}