#include <stdlib.h>
#include <string.h>

#include "parser.h"

int get_quantity_values_inline(char *line, char delimiter)
{
    int count = 0;
    for (int i = 0; line[i] != '\0'; i++)
    {
        if (line[i] == ',')
        {
            count++;
        }
    }

    return ++count;
};

IntArray parse_char_to_int_array(char *content, char delimiter)
{
    IntArray array = {-1};
    int quantity_values_inline = get_quantity_values_inline(content, delimiter);
    int *values = (int *)malloc(quantity_values_inline * sizeof(int));
    if (values == NULL)
    {
        printf("Error on allocate memory\n");
        free(content);
        return array;
    }

    char *token = strtok(content, ",");
    int index = 0;
    while (token != NULL)
    {
        values[index++] = atoi(token);
        token = strtok(NULL, ",");
    }

    array.length = quantity_values_inline;
    array.values = values;

    return array;
};