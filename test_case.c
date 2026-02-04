#include <stdio.h>
#include <math.h>
#include "calculator.h"

static int nearly_equal(double a, double b, double eps) {
    return fabs(a - b) <= eps;
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
        int ok = nearly_equal(add(2, 3), 5, EPS);
        print_line(f, "add(2,3)==5", ok);
        ok ? passed++ : failed++;
    }

    // Test subtract
    {
        int ok = nearly_equal(subtract(10, 4), 6, EPS);
        print_line(f, "subtract(10,4)==6", ok);
        ok ? passed++ : failed++;
    }

    // Test multiply
    {
        int ok = nearly_equal(multiply(2.5, 4), 10.0, EPS);
        print_line(f, "multiply(2.5,4)==10", ok);
        ok ? passed++ : failed++;
    }

    // Test divide normal
    {
        int okflag = 0;
        double r = divide(10, 2, &okflag);
        int ok = okflag && nearly_equal(r, 5.0, EPS);
        print_line(f, "divide(10,2)==5", ok);
        ok ? passed++ : failed++;
    }

    // Test divide by zero
    {
        int okflag = 1;
        double r = divide(10, 0, &okflag);
        int ok = (okflag == 0) && nearly_equal(r, 0.0, EPS);
        print_line(f, "divide(10,0) sets ok=0", ok);
        ok ? passed++ : failed++;
    }

    fprintf(f, "\nSummary: PASSED=%d FAILED=%d\n", passed, failed);
    fclose(f);

    printf("Summary: PASSED=%d FAILED=%d\n", passed, failed);

    return failed == 0 ? 0 : 1;
}
