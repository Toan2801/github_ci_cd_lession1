#include <stdio.h>
#include <math.h>
#include "calculator.h"

Std_ReturnType nearly_equal(double a, double b, double eps) {
    return fabs(a - b) <= eps ? E_OK : E_NOT_OK;
}

static void print_line(FILE *out, const char *name, int ok) {
    fprintf(out, "[%s] %s\n", ok ? "PASS" : "FAIL", name);
}

int main(void) {
    const double EPS = 1e-9;
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
        match_result ? passed++ : failed++;
    }

    // Test subtract
    {
        Std_ReturnType match_result = nearly_equal(subtract(10, 4), 6, EPS);
        match_result ? passed++ : failed++;
    }

    // Test multiply
    {
        Std_ReturnType match_result = nearly_equal(multiply(2.5, 4), 10.0, EPS);
        match_result ? passed++ : failed++;
    }

    // Test divide normal
    {
        double r = 0.0;
        Std_ReturnType ret = divide(10, 2, &r);
        Std_ReturnType match_result = nearly_equal(r, 5.0, EPS);
        match_result ? passed++ : failed++;
    }

    // Test divide by zero
    {
        double r = 0.0;
        Std_ReturnType ret = divide(10, 0, &r);
        Std_ReturnType match_result = nearly_equal(r, 0.0, EPS);
        if (ret == E_NOT_OK && match_result == E_OK) {
            passed++;
        } else {
            failed++;
        }
    }

    fprintf(f, "\nSummary: PASSED=%d FAILED=%d\n", passed, failed);
    fclose(f);

    printf("Summary: PASSED=%d FAILED=%d\n", passed, failed);

    return failed == 0 ? 0 : 1;
}
