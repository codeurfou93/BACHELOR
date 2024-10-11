#include <stdio.h>
#include "lib.h"


void test_strtoint() {
    printf("Test strtoint...\n");
    if (strtoint("1234") == 1234) {
        printf("strtoint: Test passé\n");
    } else {
        printf("strtoint: Test échoué\n");
    }
}


void test_moyenne() {
    printf("Test moyenne...\n");
    int arr[] = {1, 2, 3, 4, 5};
    if (moyenne(arr, 5) == 3.0) {
        printf("moyenne: Test passé\n");
    } else {
        printf("moyenne: Test échoué\n");
    }
}


void test_minimum() {
    printf("Test minimum...\n");
    int arr[] = {5, 3, 8, 1, 4};
    if (minimum(arr, 5) == 1) {
        printf("minimum: Test passé\n");
    } else {
        printf("minimum: Test échoué\n");
    }
}


void test_maximum() {
    printf("Test maximum...\n");
    int arr[] = {5, 3, 8, 1, 4};
    if (maximum(arr, 5) == 8) {
        printf("maximum: Test passé\n");
    } else {
        printf("maximum: Test échoué\n");
    }
}

