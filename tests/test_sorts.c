#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minunit.h"

#include "../src/algorithms/bubble_sort.c"


int tests_run = 0;

int array1[] = {-40897, 84, 0, 3029, 92, 1904, 3498, -3924, -32, 1,
                39809324, -1089, 5023, 232409, -23, -249, 789, 378546,
                8934, 789524, 8475, 47589275, 89475897};

int *intcpy(int array[], size_t length) {
    int *copy = malloc(length * sizeof(int));
    memcpy(copy, array, length * sizeof(int));
    return copy;
}

char *test_bubble_sort(void) {
    int *other_array = intcpy(array1, sizeof(array1) / sizeof(int));
    bubble_sort(other_array, sizeof(other_array) / sizeof(int));

    for (size_t i = 0; i < sizeof(other_array) / sizeof(int)-1; i++) {
        mu_assert("Error, array1 not bubble sorted.", other_array[i] < other_array[i+1]);
    }

    return 0;
}

char *all_tests(void) {
    mu_run_test(test_bubble_sort);

    return 0;
}

int main(void) {
     char *result = all_tests();
     if (result != 0) {
         printf("%s\n", result);
     }
     else {
         printf("ALL TESTS PASSED\n");
     }
     printf("Tests run: %d\n", tests_run);

     return result != 0;
}
