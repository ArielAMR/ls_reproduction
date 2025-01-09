/*
** EPITECH PROJECT, 2024
** get_path_list.c
** File description:
** get path list
*/

#include <sys/stat.h>
#include <stdlib.h>
#include "my.h"

char **get_path_list(int const argc, char **argv, int const do_dir)
{
    int const nb_path = count_object(argc, argv, do_dir);
    char **path_list = malloc(sizeof(char *) * (nb_path + 1));
    struct stat path_stats;
    int i = 0;

    for (int j = 1; j < argc; j++) {
        stat(argv[j], &path_stats);
        if (*argv[j] != '-' && S_ISDIR(path_stats.st_mode) == do_dir) {
            path_list[i] = argv[j];
            i++;
        }
    }
    path_list[i] = NULL;
    return path_list;
}
