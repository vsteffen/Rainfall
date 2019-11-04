#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int		main(int ac, char **av) {
	if (atoi(av[1]) == 0x1a7) {
		char *new_av[2] = {strdup("/bin/sh"), NULL};
		gid_t egid = getegid();
		uid_t euid = geteuid();
		setresgid(egid, egid, egid);
		setresuid(euid, euid, euid);
		execv("/bin/sh", new_av);
	}
	else {
		fprintf(stderr, "No !\n");
	}
	return (0);
}
