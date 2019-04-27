/*
** EPITECH PROJECT, 2018
** libcsv
** File description:
** The external dependencies.
*/

#include "types.h"

#ifndef CSV_EXTERNS_H
#define CSV_EXTERNS_H

extern void my_free(void *ptr);

extern int my_strcmp(const char *a, const char *b);

extern void *my_malloc(size_t n);
extern void *my_realloc(void *ptr, size_t old_size, size_t new_size);

extern char *my_strdup(const char *str);
extern char *my_strtok(char *str, const char *tok);

#endif
