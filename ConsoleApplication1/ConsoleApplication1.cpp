// CalculatorProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Calculator.h"

using namespace std;
int main()
{
    double x, y, result;
    char oper = '+';
    string s;
    cout << "Welcome to calc, enter your expression\n";
    cin >> x >> oper >> y;
    s = to_string(x) + oper + to_string(y);
    Calculator c;
    while (s != "quit") {
        cout << s << endl;
        if (oper == '/' && y == 0) {
            cout << "INVALID OPERATION: Cannot divide by 0.\n";
            continue;
        }
        result = c.Calculate(x, oper, y, s);
        cout << "Result of operation: " << result << endl;
        cin >> x >> oper >> y;
        s = to_string(x) + oper + to_string(y);
    }
    return 0;

};