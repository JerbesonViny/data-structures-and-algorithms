#include "insertion-sort.h"
#include "../../utils/integers/integers.h"

void insertion_sort(IntArray numbers, SortOrder sort_order)
{
    if (numbers.length <= 1)
    {
        return;
    }

    int (*compare_function)(int, int) = sort_order == DESCENDING ? left_values_is_less_than_right_value : left_values_is_greater_than_right_value;

    for (int current_position = 1; current_position < numbers.length; current_position++)
    {
        int current_value = numbers.values[current_position];
        int left_position = current_position - 1;

        while (left_position >= 0 && compare_function(numbers.values[left_position], current_value))
        {
            numbers.values[left_position + 1] = numbers.values[left_position];
            --left_position;
        }

        numbers.values[left_position + 1] = current_value;
    }
};