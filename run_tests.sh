#!/bin/bash
gcc tests/test_suite.c -Wall -Wextra -pedantic -std=c11 -lm -o test_suite --coverage &&
./test_suite -v | tests/greenest.sh

for option in "$@"
do
case $option in
    -c|--coverage)
    gcov tests/test_suite.c -o .
    ;;

    -r|--remove)
    rm -f test_suite
    rm -f ./*.gc*
    if [ -d "coverage" ]; then
        rm -f coverage.info
        rm -rf coverage
    fi
    ;;

    -h|--html)
    lcov -c -d . -o coverage.info
    genhtml coverage.info -o coverage
    xdg-open coverage/index.html
    ;;

esac
done
