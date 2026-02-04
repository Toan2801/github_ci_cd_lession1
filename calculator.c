#include <stdio.h>
#include "calculator.h"

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

Std_ReturnType divide(double a, double b, double* result) {
    Std_ReturnType ret = E_NOT_OK;
    if (b == 0.0) {
        printf("Error: Division by zero!\n");
    } else {
        ret = E_OK;
        *result = a / b;
    }
    return ret;
}

int main(void) {
    return 0;
}
