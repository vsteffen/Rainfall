#include <string.h>
#include <stdlib.h>

int language = 0;

void    greetuser(char *str) {
        char str_hi[0x40];
        if (language == 1) {
                strcpy(str_hi, "Hyvää päivää "); // 18 length
        }
        else if (language == 2) {
                strcpy(str_hi, "Goedemiddag! ");
        }
        else {
                strcpy(str_hi, "Hello ");
        }
        strcat(str_hi, str);
        puts(str_hi);
}

int main(int ac, char **av)
{
        char    buff1[0x4c];
        char    buff2[0x33];
        char    *env;

        if (ac != 3)
                return (1);
        memset(buff1, 0, 0x4c);
        strncpy(buff1, av[1], 0x28);
        strncpy(buff1 + 0x28, av[2], 0x20);
        env = getenv("LANG");
        if (env)
        {
                if (memcmp(env, "fi", 2) == 0)
                        language = 1;
                else if (memcmp(env, "nl", 2) == 0)
                        language = 2;
        }
        memcpy(buff2, buff1, 0x4c);
        greetuser(buff2);
}
