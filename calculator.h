#ifndef CALCULATOR_H
#define CALCULATOR_H

double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);

/* Return 0 if division by zero, set *ok = 0 */
double divide(double a, double b, int *ok);

#endif
