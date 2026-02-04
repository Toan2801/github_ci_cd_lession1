#include <stdio.h>
#include <math.h>
#include "calculator.h"

Std_ReturnType nearly_equal(double a, double b, double eps) {
    return fabs(a - b) <= eps ? E_OK : E_NOT_OK;
}

int main(void) {
    const double EPS = 0.001;
    int passed = 0, failed = 0;

    FILE *f = fopen("report.txt", "w");
    if (!f) {
        fprintf(stderr, "Cannot open report.txt for writing\n");
        return 2;
    }

    fprintf(f, "=== Calculator Test Report ===\n");

    // Test add
    {
        Std_ReturnType match_result = nearly_equal(add(2, 3), 5, EPS);
        if (match_result == E_OK) {
            fprintf(f, "Test case 1 PASSED\n");
            passed++;
        } else {
            fprintf(f, "Test case 1 FAILED\n");
            failed++;
        }
    }

    // Test subtract
    {
        Std_ReturnType match_result = nearly_equal(subtract(10, 4), 6, EPS);
        if (match_result == E_OK) {
            fprintf(f, "Test case 2 PASSED\n");
            passed++;
        } else {
            fprintf(f, "Test case 2 FAILED\n");
            failed++;
        }
    }

    // Test multiply
    {
        Std_ReturnType match_result = nearly_equal(multiply(2.5, 4), 10.0, EPS);
        if (match_result == E_OK) {
            fprintf(f, "Test case 3 PASSED\n");
            passed++;
        } else {
            fprintf(f, "Test case 3 FAILED\n");
            failed++;
        }
    }

    // Test divide normal
    {
        double r = 0.0;
        Std_ReturnType ret = divide(10, 2, &r);
        Std_ReturnType match_result = nearly_equal(r, 3.0, EPS);
        if (match_result == E_OK) {
            fprintf(f, "Test case 4 PASSED\n");
            passed++;
        } else {
            fprintf(f, "Test case 4 FAILED\n");
            failed++;
        }
    }

    // Test divide by zero
    {
        double r = 0.0;
        Std_ReturnType ret = divide(10, 0, &r);
        Std_ReturnType match_result = nearly_equal(r, 0.0, EPS);
        if (ret == E_NOT_OK && match_result == E_OK) {
            fprintf(f, "Test case 5 PASSED\n");
            passed++;
        } else {
            fprintf(f, "Test case 5 FAILED\n");
            failed++;
        }
    }

    fprintf(f, "\nSummary: PASSED=%d FAILED=%d\n", passed, failed);
    fclose(f);

    printf("Summary: PASSED=%d FAILED=%d\n", passed, failed);

    return failed == 0 ? 0 : 1;
}
