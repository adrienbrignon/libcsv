/*
** EPITECH PROJECT, 2018
** libcsv
** File description:
** Load a CSV file.
*/

#include <errno.h>
#include <stdio.h>

#include "csv.h"

static int load_keys(csv_t *csv, FILE *fp, size_t *y)
{
    size_t n = 0;
    ssize_t len = 0;
    char *tok = NULL;
    char *line = NULL;

    if ((len = getline(&line, &n, fp)) == EOF)
        return -1;

    line[len - 1] = '\0';
    tok = my_strtok(line, ",");

    for (*y = 0; tok != NULL; (*y)++, tok = my_strtok(NULL, ",")) {
        if (EXTEND(csv->keys, *y) == NULL)
            return -1;
        if ((csv->keys[*y] = my_strdup(tok)) == NULL)
            return -1;
    }

    return 0;
}

static int load_values(csv_t *csv, FILE *fp, size_t *y)
{
    size_t n = 0;
    char *line = NULL;

    for (*y = 0; getline(&line, &n, fp) != EOF; (*y)++) {
        char *tok = my_strtok(line, ",");

        if (EXTEND(csv->values, *y) == NULL)
            return -1;

        csv->values[*y] = NULL;

        for (size_t x = 0; x < csv->columns; x++, tok = my_strtok(NULL, ",")) {
            if (tok == NULL || EXTEND(csv->values[*y], x) == NULL)
                return -1;
            if ((csv->values[*y][x] = my_strdup(tok)) == NULL)
                return -1;
        }
    }

    return 0;
}

int csv_load(csv_t *csv, const char *path)
{
    FILE *fp = NULL;

    if ((fp = fopen(path, "r")) == NULL)
        return -1;
    if (load_keys(csv, fp, &csv->columns) < 0)
        return -1;
    if (load_values(csv, fp, &csv->rows) < 0)
        return -1;

    fclose(fp);

    return 0;
}
