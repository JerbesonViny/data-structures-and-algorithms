#include "selection-sort.h"
#include "../../utils/integers/integers.h"

void selection_sort(IntArray numbers, SortOrder sort_order)
{
    if (numbers.length <= 1)
    {
        return;
    }

    int (*compare_function)(int, int) = sort_order == DESCENDING ? left_values_is_greater_than_right_value : left_values_is_less_than_right_value;

    for (int i = 0; i < numbers.length - 1; i++)
    {
        int min_or_max_index = i;
        for (int j = i + 1; j < numbers.length; j++)
            if (compare_function(numbers.values[j], numbers.values[min_or_max_index]))
                min_or_max_index = j;

        if (min_or_max_index != i)
        {
            int aux = numbers.values[min_or_max_index];
            numbers.values[min_or_max_index] = numbers.values[i];
            numbers.values[i] = aux;
        }
    }
};