#include "bubble-sort.h"
#include "../../utils/integers/integers.h"

void bubble_sort(IntArray numbers, SortOrder sort_order)
{
    if (numbers.length <= 1)
    {
        return;
    }

    int (*compare_function)(int, int) = sort_order == DESCENDING ? left_values_is_less_than_right_value : left_values_is_greater_than_right_value;

    for (int macro_index = 0; macro_index < numbers.length - 1; macro_index++)
    {
        int one_element_are_swapped = 0;

        for (int micro_index = 0; micro_index < numbers.length - macro_index - 1; micro_index++)
        {
            if (compare_function(numbers.values[micro_index], numbers.values[micro_index + 1]))
            {
                one_element_are_swapped = 1;
                int aux = numbers.values[micro_index];
                numbers.values[micro_index] = numbers.values[micro_index + 1];
                numbers.values[micro_index + 1] = aux;
            }
        }

        if (!one_element_are_swapped)
        {
            break;
        }
    }
};