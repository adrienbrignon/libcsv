/*
** EPITECH PROJECT, 2018
** libcsv
** File description:
** Get data from row.
*/

#include "csv.h"

char *csv_get(csv_t *csv, const char *key, size_t row)
{
    ssize_t index = 0;

    if (row >= csv->rows)
        return NULL;
    if ((index = csv_indexof(csv, key)) < 0)
        return NULL;

    return (char *) csv->values[row][index];
}
