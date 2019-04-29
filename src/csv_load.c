/*
** EPITECH PROJECT, 2018
** libcsv
** File description:
** Load a CSV file.
*/

#include <errno.h>
#include <stdio.h>

#include "csv.h"

static ssize_t readfile(FILE *fp, char **dest)
{
    size_t n = 0;
    ssize_t s = 0;

    if ((s = getline(dest, &n, fp)) == EOF)
        return -1;

    (*dest)[s - 1] = '\0';

    return s;
}

static int load_keys(csv_t *csv, FILE *fp, size_t *y)
{
    ssize_t len = 0;
    char *tok = NULL;
    char *line = NULL;

    if ((len = readfile(fp, &line)) == EOF)
        return -1;

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
    char *line = NULL;

    for (*y = 0; readfile(fp, &line) != EOF; (*y)++) {
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
