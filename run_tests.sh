#!/bin/bash
gcc tests/test_suite.c -Wall -Wextra -pedantic -std=c11 -lm -o test_suite --coverage &&
./test_suite -v | tests/greenest.sh &&
gcov tests/test_suite.c -o .
if [ $# -eq 1 ] && [ "$1" == "--remove" ]; then
    rm test_suite
    rm *.gc*
fi
