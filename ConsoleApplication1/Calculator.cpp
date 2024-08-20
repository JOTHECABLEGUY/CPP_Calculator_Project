#include "Calculator.h"
#include <cmath>
#include <iostream>
#include <regex>
using namespace std;
class Calculator {

public:
	double Calculate(const string orig_input, double x, char oper, double y) {
		switch (oper) {
		case('-'):
			return x - y;
		case('+'):
			return x + y;
		case('/'):
			return x / y;
		case('*'):
			return x * y;
		default:
			if (orig_input.find("**") != string::npos) {
				vector<double> inputs = extract_numbers_from_expr(orig_input, "**");
				return pow(inputs[0], inputs[1]);
			}
			if (orig_input.find("sqrt") != string::npos) {
				vector<double> inputs = extract_numbers_from_expr(orig_input, "sqrt");
				return sqrt(inputs[0]);
			}
			if (orig_input.find("log") != string::npos) {
				vector<double> inputs = extract_numbers_from_expr(orig_input, "log");
				return log2(inputs[0]) / log2(inputs[1]);
			}
			return 0.0;
		}
		return 0.0;
	};
private:
	vector<double> extract_numbers_from_expr(const string &expr, const string oper) {
		regex e;
		vector<double> ret_vec;
		if (oper == "**") {
			regex e("(.*)" + oper + "(.*)");
		}
		else { regex e("(" + oper + ")\((.*)\)"); };
		smatch sm;    // same as std::match_results<const char*> cm;
		regex_match(expr, sm, e);
		if (not sm.size()) {
			return ret_vec;
		}
		string match_group = sm[2];
		vector<string> params = tokenize(match_group, ',');
		for (string s : params) {
			ret_vec.push_back(stod(s));
		}
		return ret_vec;
	};
	vector<string> tokenize(const string s, char del) {
		int right, left = -1;
		vector<string> ret_vec;
		while (right != -1) {
			left = right + 1;
			right = s.find(del);
			string new_str = s.substr(left, right - left);
			ret_vec.push_back(new_str);
		}
		return ret_vec;
	};
};