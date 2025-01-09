/*
** EPITECH PROJECT, 2024
** get_blocks
** File description:
** get blocks nb
*/

#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include "my.h"

void get_blocks(char *filename, duo_flag_t const list[])
{
    DIR *ptr = opendir(filename);
    struct dirent *dir = readdir(ptr);
    struct stat stats;
    int count = 0;

    while (dir != NULL) {
        stat(get_path(filename, dir->d_name), &stats);
        if (*dir->d_name != '.' ||
            (*dir->d_name == '.' && list[0].is_passed == 1))
            count += stats.st_blocks;
        dir = readdir(ptr);
    }
    write(1, "total ", 6);
    my_put_nbr(count / 2);
    write(1, "\n", 1);
    closedir(ptr);
}
