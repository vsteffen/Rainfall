#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int ac, char **av, char **env)
{
        char    str[0x28];
        int     n;

        if ((n = atoi(av[1])) > 9)
                return(1);

        memcpy(str, av[2], n * 4);
        if (n == 0x574f4c46)
                execl("/bin/sh", "sh", NULL);
        return (0);
}