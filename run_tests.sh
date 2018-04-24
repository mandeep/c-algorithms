#!/bin/bash
gcc tests/test_suite.c -Wall -Wextra -pedantic -o test_suite -std=c11
./test_suite
