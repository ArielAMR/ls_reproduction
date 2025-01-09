/*
** EPITECH PROJECT, 2024
** my_ls_l.c
** File description:
** ls -l
*/

#include <unistd.h>
#include <time.h>
#include <pwd.h>
#include <sys/stat.h>
#include <grp.h>
#include "my.h"

static int oct(int nb)
{
    int oct = 0;
    int i = 1;

    while (nb != 0) {
        oct += nb % 8 * i;
        nb /= 8;
        i *= 10;
    }
    return oct;
}

static void give_type(struct stat *stats)
{
    if (S_ISREG(stats->st_mode) == 1)
        write(1, "-", 1);
    if (S_ISDIR(stats->st_mode) == 1)
        write(1, "d", 1);
    if (S_ISLNK(stats->st_mode) == 1)
        write(1, "l", 1);
    if (S_ISCHR(stats->st_mode) == 1)
        write(1, "c", 1);
    if (S_ISBLK(stats->st_mode) == 1)
        write(1, "b", 1);
    if (S_ISFIFO(stats->st_mode) == 1)
        write(1, "f", 1);
    if (S_ISSOCK(stats->st_mode) == 1)
        write(1, "s", 1);
}

static void rwx(int rights)
{
    if (rights >= 4)
        write(1, "r", 1);
    else
        write(1, "-", 1);
    if (rights == 2 || rights == 6 || rights == 7)
        write(1, "w", 1);
    else
        write(1, "-", 1);
    if (rights == 1 || rights == 3 || rights == 5 || rights == 7)
        write(1, "x", 1);
    else
        write(1, "-", 1);
}

static void put_rights(struct stat *stats)
{
    int rights;

    rights = oct(stats->st_mode & 0777);
    give_type(stats);
    rwx(rights / 100);
    rwx(rights / 10 % 10);
    rwx(rights % 10);
}

static void put_names(struct stat *stats)
{
    struct passwd *pw = getpwuid(stats->st_uid);
    struct group *gr = getgrgid(stats->st_gid);

    my_putstr(pw->pw_name);
    my_putstr(" ");
    my_putstr(gr->gr_name);
}

static void put_date(struct stat *stats)
{
    time_t time = stats->st_mtime;
    char *buff = ctime(&time);

    write(1, buff + 4, 12);
}

void my_putname_l(char const *filename, char const *filepath)
{
    struct stat stats;

    stat(filepath, &stats);
    put_rights(&stats);
    write(1, " ", 1);
    my_put_nbr(stats.st_nlink);
    write(1, " ", 1);
    put_names(&stats);
    write(1, " ", 1);
    my_put_nbr(stats.st_size);
    write(1, " ", 1);
    put_date(&stats);
    write(1, " ", 1);
    my_putstr(filename);
}
