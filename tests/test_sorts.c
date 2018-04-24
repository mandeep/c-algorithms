#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "greatest.h"

#include "../src/algorithms/bubble_sort.c"
#include "../src/algorithms/counting_sort.c"
#include "../src/algorithms/heap_sort.c"


int max(int array[], int length) {
    int maximum = 0;
    for (int i = 0; i < length; i++) {
        if (array[i] > maximum) {
            maximum = array[i];
        }
    }
    return maximum;
}

TEST test_bubble_sort(void) {
    srand(time(NULL));
    int random_number = rand() % 10;
    int array[random_number];
    for (int i = 0; i < random_number; i++) {
        array[i] = rand();
    }

    bubble_sort(array, random_number);

    for (int i = 0; i < random_number-1; i++) {
        ASSERT(array[i] <= array[i+1]);
    }
    PASS();
}

TEST test_counting_sort(void) {
    srand(time(NULL));
    int random_number = rand() % 10;
    int array[random_number];
    for (int i = 0; i < random_number; i++) {
        array[i] = rand();
    }

    int sorted_array[random_number];

    for (int i = 0; i < random_number; i++) {
        sorted_array[i] = 0;
    }
    
    counting_sort(array, sorted_array, random_number, max(array, random_number));

    for (int i = 0; i < random_number-1; i++) {
        ASSERT(sorted_array[i] <= sorted_array[i+1]);
    }
    PASS();
}

TEST test_heap_sort(void) {
    srand(time(NULL));
    int random_number = rand() % 10;
    int array[random_number];
    for (int i = 0; i < random_number; i++) {
        array[i] = rand();
    }
    
    heap_sort(array, random_number);

    for (int i = 0; i < random_number-1; i++) {
        ASSERT(array[i] <= array[i+1]);
    }
    PASS();
}

SUITE(sorting_algorithms) {
    RUN_TEST(test_bubble_sort);
    RUN_TEST(test_counting_sort);
    RUN_TEST(test_heap_sort);
}
