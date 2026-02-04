#include <stdio.h>

/* Hàm cộng */
double add(double a, double b) {
    return a + b;
}

/* Hàm trừ */
double subtract(double a, double b) {
    return a - b;
}

/* Hàm nhân */
double multiply(double a, double b) {
    return a * b;
}

/* Hàm chia
 * Trả về 0 nếu chia cho 0 và in cảnh báo
 */
double divide(double a, double b) {
    if (b == 0.0) {
        fprintf(stderr, "Error: Division by zero!\n");
        return 0.0;
    }
    return a / b;
}

int main(void) {
    double x = 10.0;
    double y = 5.0;

    printf("Calculator demo\n");
    printf("----------------\n");

    printf("Add:        %.2f + %.2f = %.2f\n", x, y, add(x, y));
    printf("Subtract:   %.2f - %.2f = %.2f\n", x, y, subtract(x, y));
    printf("Multiply:   %.2f * %.2f = %.2f\n", x, y, multiply(x, y));
    printf("Divide:     %.2f / %.2f = %.2f\n", x, y, divide(x, y));

    /* Test chia cho 0 */
    printf("\nTest division by zero:\n");
    divide(x, 0.0);

    return 0;
}
