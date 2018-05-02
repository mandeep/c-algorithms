#!/bin/bash
gcc tests/test_suite.c -Wall -Wextra -pedantic -o test_suite -std=c11 &&
./test_suite -v | tests/greenest.sh &&
rm test_suite
