#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "./minunit.h"
#include "util.h"

int tests_run = 0;

static char * test1() {
    char *res = impcode_v4(0);
    char *message = "test1 failed: impcode_v4 should return 'network unreachable'";
    mu_assert(message, res == "network unreachable");
    return NULL;
}

static char * test2() {
    char *res = impcode_v4(28);
    char *message = "test2 failed: impcode_v4 should return '[unknown code]'";
    mu_assert(message, res == "[unknown code]");
    return NULL;
}

static char * all_tests() {
    mu_run_test(test1);
    mu_run_test(test2);
    return NULL;
}

int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != NULL) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}