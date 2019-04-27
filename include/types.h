/*
** EPITECH PROJECT, 2018
** libcsv
** File description:
** The library types.
*/

#include <stddef.h>
#include <sys/types.h>

#ifndef CSV_TYPES_H_
#define CSV_TYPES_H_

typedef struct csv {
    size_t rows;
    size_t columns;

    const char **keys;
    const char ***values;
} csv_t;

#endif


