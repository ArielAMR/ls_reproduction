/*
** EPITECH PROJECT, 2024
** does_it_exist.c
** File description:
** does it exist ?
*/

#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include "my.h"

static int can_i_access(char *str)
{
    DIR *ptr;

    errno = 0;
    ptr = opendir(str);
    if (errno == 2) {
        write(2, "ls: cannot access \'", 19);
        my_putstr(str);
        write(2, "\': No such file or directory\n", 29);
        return 84;
    }
    closedir(ptr);
    return 0;
}

int does_it_exist(int argc, char **argv)
{
    int ret = 0;

    for (int i = 1; i < argc; i++) {
        if (*argv[i] != '-' && ret != 0)
            can_i_access(argv[i]);
        if (*argv[i] != '-' && ret == 0)
            ret = can_i_access(argv[i]);
    }
    return ret;
}
