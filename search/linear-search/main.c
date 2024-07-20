#include <stdlib.h>
#include <stdio.h>

#include "../../utils/files/files.h"
#include "../../utils/parser/parser.h"
#include "./linear-search.h"

void display_message(int value, int founded)
{
    if (founded == -1)
    {
        printf("The value %d was not found\n", value);
    }
    else
    {
        printf("The value %d was found\n", value);
    }
}

int main()
{
    char *filename = "data/ascending-numeric-values.txt";
    char *file_content = read_file(filename);
    IntArray numbers = parse_char_to_int_array(file_content, ",");

    int existent_value = 7;
    int unexistent_value = 32;

    int founded = linear_search(existent_value, numbers);
    int unfounded = linear_search(unexistent_value, numbers);

    display_message(existent_value, founded);
    display_message(unexistent_value, unfounded);

    free(file_content);
    free(numbers.values);

    return 0;
}