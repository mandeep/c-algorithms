#!/bin/bash
gcc tests/test_suite.c -Wall -Wextra -pedantic -std=c11 -lm -o test_suite --coverage &&
./test_suite -v | tests/greenest.sh &&
rm test_suite
gcov tests/test_suite.c -o .
