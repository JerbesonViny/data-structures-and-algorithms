#include <stdio.h>
#include <stdlib.h>

#include "../../utils/files/files.h"
#include "../../utils/parser/parser.h"
#include "./binary-search.h"

void is_equals_to(int expected, int received)
{
    if (expected == received)
        printf("%d is equals to %d -> True\n", expected, received);
    else
        printf("%d is equals to %d -> False\n", expected, received);
}

void is_not_equals_to(int first_value, int second_value)
{
    if (first_value != second_value)
        printf("%d isn't equals to %d -> True\n", first_value, second_value);
    else
        printf("%d isn't equals to %d -> False\n", first_value, second_value);
}

void should_found_values(IntArray numbers)
{
    printf("--- Should found values ---\n");
    for (int index = 0; index < numbers.length; index++)
    {
        int value = numbers.values[index];
        int element_position = binary_search(value, numbers);
        printf("Test: Should found value in array of integers\nResult: ");
        is_not_equals_to(element_position, -1);
    }
}

void should_not_found_values(IntArray numbers)
{
    printf("--- Shouldn't found values ---\n");
    int value_greater_than_maximum = 30;
    int value_greater_than_maximum_element_position = binary_search(value_greater_than_maximum, numbers);
    printf("Test: Shouldn't found value in array of integers because this value is greater than maximun value of array\nResult: ");
    is_equals_to(value_greater_than_maximum_element_position, -1);

    int value_less_than_minimun = -20;
    int value_less_than_minimun_element_position = binary_search(value_less_than_minimun, numbers);
    printf("Test: Shouldn't found value in array of integers because this value is less than minimum value of array\nResult: ");
    is_equals_to(value_less_than_minimun_element_position, -1);

    IntArray empty_array = {0};
    int unexistent_value = 1;
    int unexistent_value_element_position = binary_search(unexistent_value, empty_array);
    printf("Test: Shouldn't found value in array of integers because this array is empty\nResult: ");
    is_equals_to(unexistent_value_element_position, -1);
}

void tests(IntArray numbers)
{
    should_found_values(numbers);
    printf("\n");
    should_not_found_values(numbers);
    printf("\n");
}

int main(void)
{
    char *filename = "data/ascending-numeric-values.txt";
    char *content = read_file(filename);
    IntArray numbers = parse_char_to_int_array(content, ",");

    tests(numbers);

    free(content);
    free(numbers.values);

    return 0;
}