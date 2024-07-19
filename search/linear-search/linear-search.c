#include "./linear-search.h"

int linear_search(int searched_value, IntArray numbers)
{
    for (int index = 0; index < numbers.length; index++)
    {
        if (numbers.values[index] == searched_value)
        {
            return index;
        }
    }

    return -1;
};