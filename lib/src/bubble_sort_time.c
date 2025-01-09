/*
** EPITECH PROJECT, 2024
** bubble_sort_time
** File description:
** a bubble sort by time
*/

#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include "my.h"

static char **loop_child(char **list, char const *filename)
{
    struct stat stats1;
    struct stat stats2;
    char *tmp;

    for (int j = 0; list[j + 1] != NULL; j++) {
        stat(get_path(filename, list[j]), &stats1);
        stat(get_path(filename, list[j + 1]), &stats2);
        if (stats1.st_mtime < stats2.st_mtime) {
            tmp = list[j];
            list[j] = list[j + 1];
            list[j + 1] = tmp;
        }
    }
    return list;
}

static char **loop_base(char **list)
{
    struct stat stats1;
    struct stat stats2;
    char *tmp;

    for (int j = 0; list[j + 1] != NULL; j++) {
        stat(list[j], &stats1);
        stat(list[j + 1], &stats2);
        if (stats1.st_mtime < stats2.st_mtime) {
            tmp = list[j];
            list[j] = list[j + 1];
            list[j + 1] = tmp;
        }
    }
    return list;
}

char **bubble_sort_time(char **list, char const *filename)
{
    for (int i = 0; list[i] != NULL; i++) {
        if (filename == NULL)
            list = loop_base(list);
        else
            list = loop_child(list, filename);
    }
    return list;
}
