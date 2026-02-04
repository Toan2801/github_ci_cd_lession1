#ifndef CALCULATOR_H
#define CALCULATOR_H

#define E_OK      0x00u
#define E_NOT_OK  0x01u

typedef unsigned char Std_ReturnType;


double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);

/* Return 0 if division by zero, set *ok = 0 */
Std_ReturnType divide(double a, double b, double* result);

#endif
