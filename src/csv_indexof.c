/*
** EPITECH PROJECT, 2018
** libcsv
** File description:
** Get the index of a key.
*/

#include "csv.h"

ssize_t csv_indexof(csv_t *csv, const char *needle)
{
    for (size_t column = 0; column < csv->columns; column++) {
        if (my_strcmp(needle, csv->keys[column]) == 0)
            return column;
    }

    return -1;
}
