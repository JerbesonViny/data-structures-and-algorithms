#include <stdio.h>
#include <stdlib.h>

#include "../../utils/files/files.h"
#include "../../utils/parser/parser.h"
#include "insertion-sort.h"

int main(void)
{
    char *filename = "./data/smallest-random-values.txt";
    char *content = read_file(filename);
    IntArray numbers = parse_char_to_int_array(content, ",");

    insertion_sort(numbers, DESCENDING);

    for (int position = 0; position < numbers.length; position++)
    {
        if (position == numbers.length - 1)
        {
            printf("%d\n", numbers.values[position]);
        }
        else
        {
            printf("%d - ", numbers.values[position]);
        }
    }

    /* insertion_sort(numbers, ASCENDING);

    for (int position = 0; position < numbers.length; position++)
    {
        if (position == numbers.length - 1)
        {
            printf("%d\n", numbers.values[position]);
        }
        else
        {
            printf("%d - ", numbers.values[position]);
        }
    } */

    return 0;
}