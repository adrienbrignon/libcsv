/*
** EPITECH PROJECT, 2018
** libcsv
** File description:
** The library main header.
*/

#include "types.h"
#include "externs.h"

#ifndef CSV_H_
#define CSV_H_

#define ERROR(status, error) (((errno = error) * 0) + status)
#define EXTEND(ptr, i) \
    ((ptr = my_realloc(ptr, i * sizeof *ptr, (i + 1) * sizeof *ptr)))

void csv_destroy(csv_t *csv);

int csv_load(csv_t *csv, const char *path);

ssize_t csv_indexof(csv_t *csv, const char *needle);

char *csv_get(csv_t *csv, const char *key, size_t row);

csv_t *csv_init(void);

#endif
