/*
** EPITECH PROJECT, 2018
** libcsv
** File description:
** Create a new CSV instance.
*/

#include "csv.h"

csv_t *csv_init(void)
{
    csv_t *csv = NULL;

    if ((csv = my_malloc(sizeof *csv)) == NULL)
        return NULL;

    csv->rows = 0;
    csv->columns = 0;
    csv->keys = NULL;
    csv->values = NULL;

    return csv;
}
