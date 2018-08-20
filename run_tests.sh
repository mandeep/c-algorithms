#!/bin/bash
gcc tests/test_suite.c -Wall -Wextra -pedantic -std=c11 -lm -o test_suite --coverage &&
./test_suite -v | tests/greenest.sh

if [ $# -gt 0 ] && [ "$1" == "--coverage" ]; then
    gcov tests/test_suite.c -o .
fi

if [ $# -gt 1 ] && [ "$2" == "--remove" ]; then
    rm test_suite
    rm ./*.gc*
fi
