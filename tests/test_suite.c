#include "test_searches.c"
#include "test_sorts.c"


GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
    GREATEST_MAIN_BEGIN();
    RUN_SUITE(sorting_algorithms);
    RUN_SUITE(searching_algorithms);
    GREATEST_MAIN_END();
}