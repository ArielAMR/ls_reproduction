/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my functions prototypes
*/

#ifndef MY_H_
    #define MY_H_

typedef struct duo_flag_s {
    char c;
    int is_passed;
} duo_flag_t;

typedef struct counts {
    int dir;
    int file;
    int tot;
} counts_t;

int my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_ls(int const argc, char **argv);
void get_flags(duo_flag_t list[], char const *flag);
int count_object(int const argc, char **argv, int const do_dir);
int my_strlen(char const *str);
char *get_path(char const *dest, char const *src);
char **my_revlist(char **list);
char **get_path_list(int const argc, char **argv, int const do_dir);
void my_putname_l(char const *filename, char const *filepath);
void get_blocks(char *filename, duo_flag_t const list[]);
int does_it_exist(int argc, char **argv);
char **bubble_sort_time(char **list, char const *foldername);

#endif
