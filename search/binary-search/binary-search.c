#include <math.h>
#include <stdio.h>

#include "./binary-search.h"

int binary_search(int searched_value, IntArray numbers)
{
    if (numbers.length == 0)
        return -1;

    int quantity_of_elements = numbers.length;
    int min_value = numbers.values[0];
    int max_value = numbers.values[quantity_of_elements - 1];

    if (searched_value < min_value || searched_value > max_value)
        return -1;

    int keep_continue_searching = 1;
    int position = -1;

    int left_margin_position = 0;
    int right_margin_position = quantity_of_elements - 1;

    while (keep_continue_searching != 0)
    {

        int middle_position = floor((left_margin_position + right_margin_position) / 2.0);
        int value = numbers.values[middle_position];

        if (searched_value == value)
        {
            position = middle_position;
            keep_continue_searching = 0;
        }
        else if (searched_value > value && searched_value <= max_value)
        {
            left_margin_position = ++middle_position;
            min_value = value;
        }
        else if (searched_value < value && searched_value >= min_value)
        {
            right_margin_position = --middle_position;
            max_value = value;
        }
        else
        {
            keep_continue_searching = 0;
        }
    };

    return position;
};