/*
** EPITECH PROJECT, 2018
** libcsv
** File description:
** Destroy a CSV instance.
*/

#include "csv.h"

void csv_destroy(csv_t *csv)
{
    for (size_t y = 0; y < csv->rows; y++) {
        for (size_t x = 0; x < csv->columns; x++)
            my_free((char *) csv->values[y][x]);

        my_free(csv->values[y]);
    }

    for (size_t x = 0; x < csv->columns; x++)
        my_free((char *) csv->keys[x]);

    my_free(csv->keys);
    my_free(csv->values);
    my_free(csv);
}
