#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Calculator
{
public:
	double Calculate(const string orig_input, double x, char oper, double y){};
private:
	vector<double> extract_numbers_from_expr(const string &expr, const string oper) {};
	vector<string> tokenize(const string s, char del) {};
};

