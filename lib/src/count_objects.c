/*
** EPITECH PROJECT, 2024
** count_object.c
** File description:
** count object
*/

#include "my.h"
#include <sys/stat.h>

int count_object(int const argc, char **argv, int const do_dir)
{
    int count = 0;
    struct stat path_stats;
    int is_dir = 0;

    for (int i = 1; i != argc; i++) {
        stat(argv[i], &path_stats);
        is_dir = S_ISDIR(path_stats.st_mode);
        if (*argv[i] != '-' && is_dir == do_dir)
            count++;
    }
    return count;
}
