#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *service = NULL;
char *auth = NULL;

int main(int ac, char **av) {
	char buff[0x80];

	while (42) {
		printf("%p, %p \n", auth, service);
		if (!fgets(buff, 0x80, stdin))
		return (0);

		if (strncmp(buff, "auth ", 0x5) == 0) {
			auth = malloc(0x4);
			*auth = 0;
			if (strlen(&buff[5]) == 0x1e)
				strcpy(auth, &buff[5]);
		}
		if (strncmp(buff, "reset", 0x5) == 0) {
			free(auth);
		}
		if (strncmp(buff, "service", 0x6) == 0) {
			service = strdup(buff + 0x7);
		}
		if (strncmp(buff, "login", 0x5) == 0) {
			if (*(int *)&auth[0x20])
				system("/bin/sh");
			else
				fwrite("Password:\n", 1, 10, stdout);
		}
	}
}
