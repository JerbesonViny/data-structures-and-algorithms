#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "files.h"

FILE *open_file(char *filename)
{
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error on open file %s\n", filename);
        return NULL;
    }

    return file;
};

long get_file_size(FILE *file)
{
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    return ++file_size;
};

char *read_file(char *filename)
{
    FILE *file = open_file(filename);
    long file_size = get_file_size(file);

    char *content = (char *)malloc(file_size + 1);
    if (content == NULL)
    {
        printf("Error on allocate memory\n");
        fclose(file);
        return NULL;
    }

    fread(content, 1, file_size, file);
    content[file_size] = '\0';
    fclose(file);

    return content;
};
