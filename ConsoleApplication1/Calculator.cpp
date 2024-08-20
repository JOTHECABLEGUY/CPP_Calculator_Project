

#include "Calculator.h"
#include <iostream>

double Calculator::Calculate(double x, char oper, double y, std::string s)
{
    switch (oper) {
    case ('+'):
        return x + y;
    case('-'):
        return x - y;
    case('*'):
        return x * y;
    case('/'):
        return x / y;
    default:
        return 0.0;
    }
}