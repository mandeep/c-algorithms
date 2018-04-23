#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "greatest.h"

#include "../src/algorithms/bubble_sort.c"


int tests_run = 0;

int array1[] = {-40897, 84, 0, 3029, 92, 1904, 3498, -3924, -32, 1,
                39809324, -1089, 5023, 232409, -23, -249, 789, 378546,
                8934, 789524, 8475, 47589275, 89475897};
size_t array1_length = 23;

int *intcpy(int array[], size_t length) {
    int *copy = malloc(length * sizeof(int));
    memcpy(copy, array, length * sizeof(int));
    return copy;
}

TEST test_bubble_sort(void) {
    int *array = intcpy(array1, array1_length);
    bubble_sort(array, array1_length);

    for (size_t i = 0; i < array1_length-1; i++) {
        ASSERT(array[i] < array[i+1]);
    }
    PASS();
}

SUITE(suite) {
    RUN_TEST(test_bubble_sort);
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
    GREATEST_MAIN_BEGIN();
    RUN_SUITE(suite);
    GREATEST_MAIN_END();
}
