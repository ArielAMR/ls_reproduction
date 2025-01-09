/*
** EPITECH PROJECT, 2024
** my_ls.c
** File description:
** replicate the behavior of the ls bash command
*/

#include <errno.h>
#include <dirent.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <unistd.h>
#include "my.h"

static int count_childs(char const *filename)
{
    DIR *ptr = opendir(filename);
    struct dirent *dir;
    int count = 0;

    if (ptr == NULL)
        return 0;
    dir = readdir(ptr);
    while (dir != NULL) {
        count++;
        dir = readdir(ptr);
    }
    closedir(ptr);
    return count;
}

static char **get_childs_list(DIR *ptr, char **childs_list)
{
    struct dirent *dir = readdir(ptr);
    int i = 0;

    while (dir != NULL) {
        childs_list[i] = dir->d_name;
        dir = readdir(ptr);
        i++;
    }
    childs_list[i] = NULL;
    return childs_list;
}

static void each_child(DIR *ptr,
    duo_flag_t const list[], char const *foldername)
{
    char **childs_list;

    childs_list = malloc(sizeof(char *) * (count_childs(foldername) + 1));
    childs_list = get_childs_list(ptr, childs_list);
    if (list[2].is_passed == 1)
        childs_list = bubble_sort_time(childs_list, foldername);
    if (list[3].is_passed == 1)
        childs_list = my_revlist(childs_list);
    for (int i = 0; childs_list[i] != NULL; i++) {
        if (*childs_list[i] == '.' && list[0].is_passed == 0)
            continue;
        if (list[1].is_passed == 1)
            my_putname_l(childs_list[i], get_path(foldername, childs_list[i]));
        else
            my_putstr(childs_list[i]);
        my_putchar('\n');
    }
    free(childs_list);
}

static int put_errno_20(char const *foldername, duo_flag_t const list[])
{
    if (list[1].is_passed == 1)
        my_putname_l(foldername, foldername);
    else
        my_putstr(foldername);
    my_putchar('\n');
    return 0;
}

static int display_content(char const *foldername, duo_flag_t const list[])
{
    DIR *ptr = NULL;

    errno = 0;
    ptr = opendir(foldername);
    if (ptr == NULL && errno != 20 && errno != 2) {
        write(2, "ls: cannot open directory \'", 27);
        my_putstr(foldername);
        write(2, "\': Permission denied\n", 21);
        return 84;
    }
    if (errno == 2)
        return 0;
    if (errno == 20)
        return put_errno_20(foldername, list);
    each_child(ptr, list, foldername);
    closedir(ptr);
    return 0;
}

static int display(char *foldername, counts_t const *count,
    duo_flag_t const list[], int const diff)
{
    struct stat folderstats;
    int is_dir = 0;
    int ret = 0;

    stat(foldername, &folderstats);
    is_dir = S_ISDIR(folderstats.st_mode);
    if (count->dir > 0 && count->tot > 1 && is_dir == 1) {
        my_putstr(foldername);
        my_putstr(":\n");
    }
    if (list[1].is_passed == 1 && is_dir == 1)
        get_blocks(foldername, list);
    ret = display_content(foldername, list);
    if (count->dir > 1 && is_dir == 1 && diff != 0)
        my_putchar('\n');
    return ret;
}

static int display_loop(duo_flag_t list[],
    counts_t count, char **dir_list, char **file_list)
{
    int tmp_ret = 0;
    int ret = 0;

    if (count.dir == 0 && count.file == 0)
        return display(".", &count, list, 1);
    for (int i = 0; file_list[i] != NULL; i++) {
        tmp_ret = display(file_list[i], &count, list, 1);
        if (tmp_ret != 0)
            ret = tmp_ret;
    }
    if (count.dir != 0 && count.file != 0)
        my_putchar('\n');
    for (int i = 0; dir_list[i] != NULL; i++) {
        tmp_ret = display(dir_list[i], &count, list, i + 1 - count.dir);
        if (tmp_ret != 0)
            ret = tmp_ret;
    }
    return ret;
}

static char **sort(duo_flag_t list[], char **objects)
{
    if (list[2].is_passed == 1)
        objects = bubble_sort_time(objects, NULL);
    if (list[3].is_passed == 1)
        objects = my_revlist(objects);
    return objects;
}

int my_ls(int const argc, char **argv)
{
    counts_t count = {count_object(argc, argv, 1),
        count_object(argc, argv, 0), count.dir + count.file};
    duo_flag_t list[] = {{'a', 0}, {'l', 0}, {'t', 0},
        {'r', 0}, {'d', 0}, {'R', 0}};
    char **dir_list = get_path_list(argc, argv, 1);
    char **file_list = get_path_list(argc, argv, 0);
    int ret = 0;
    int tmp_ret = 0;

    ret = does_it_exist(argc, argv);
    for (int i = 1; i < argc; i++)
        get_flags(list, argv[i]);
    dir_list = sort(list, dir_list);
    file_list = sort(list, file_list);
    tmp_ret = display_loop(list, count, dir_list, file_list);
    if (ret == 0)
        ret = tmp_ret;
    free(dir_list);
    free(file_list);
    return ret;
}
