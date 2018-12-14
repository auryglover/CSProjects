/*Arianna Glover       */
/*Due December 3rd     */
/*Programming Project 3*/

#include <math.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

double xj(double a, int j, double h) {
	return a + (j * h);
}

double Function(double x) {
	double pi = 3.1415926535897;
	return (2 / sqrt(pi)) * exp(-1 * pow(x, 2));
}

double f4(double x) {
	double pi = 3.1415926535897;
	return (8 / sqrt(pi)) * exp(-1 * pow(x, 2)) * ((4 * pow(x, 4)) - (12 * pow(x, 2)) + 3);
}

double f5(double x) {
	double pi = 3.1415926535897;
	return (16 / sqrt(pi)) * x * exp(-1 * pow(x, 2)) * ((-4 * pow(x, 4)) + (20 * pow(x, 2)) - 15);
}

double SimpsonsRule(int n, double a, double b) {
	double p = 0;
	double h = (b - a) / n;
	for (int j = 1; j < n; j++) {
		if (remainder(j, 2) != 0) {
			p = p + (2 * Function(xj(a, j, h)));
		}

		else {
			p = p + (4 * Function(xj(a, j, h)));
		}
	}
	return ((h / 3) * (Function(a) + p + Function(b))) - (((b - a) / 180) * pow(h, 4) * f4(0));
}

double SimpsonsRuleN1(double a, double b) {
	double h = (b - a);
	return ((h / 3) * (Function(a) + Function(b))) - (((b - a) / 180) * pow(h, 4) * f4(0));
}

int main() {
	cout << "The roots on |f5(gamma)| are -2.02, -.959, 0, .959, and 2.02. Since we are looking at the interval [0, 1] we look at the critical points 0, .959, and 1 and plug those into f4(gamma) to find our upperbound on the error.";
	long double erf1 = 0.842700792949715;

	/*Initializations for finding the maximum of f4(gamma)*/
	double pa = 0;
	double pb = 1;
	double pc = .959;
	cout << '\n' << "f4(0) = " << f4(pa) << '\n';
	cout << "f4(1) = " << f4(pb) << '\n';
	cout << "f4(.959) = " << f4(pc) << '\n' << "Therefore, f4(0) = " << f4(pa) << " is the upperbound for the error." << '\n' << "Then," << '\n' << '\n';

	/*Initializations for evaluating the Simpson Formula*/
	int a = 0;
	int b = 1;
	int n1 = 1;
	int n2 = 2;
	int n3 = 4;
	int n4 = 8;
	double w = SimpsonsRuleN1(a, b);
	double x = SimpsonsRule(n2, a, b);
	double y = SimpsonsRule(n3, a, b);
	double z = SimpsonsRule(n4, a, b);

	/*Question 2:*/
	double l = abs(erf1 - w);
	double m = abs(erf1 - x);
	double n = abs(erf1 - y);
	double o = abs(erf1 - z);
	cout << "Question 2: Run your program with n= 1, 2, 4, 8 and give the error in each case. Explain the rate of decrease in the error that you observe in terms of the error term in Simpson's rule.";
	cout << "Simpson's Rule equals " << w << " when n = 1: " << '\n';
	cout << "|erf(1) - SR(n = 1)| = " << l << '\n';
	cout << "Simpson's Rule equals " << x << " when n = 2: " << '\n';
	cout << "|erf(1) - SR(n = 2)| = " << m << '\n';
	cout << "Simpson's Rule equals " << y << " when n = 4: " << '\n';
	cout << "|erf(1) - SR(n = 4)| = " << n << '\n';
	cout << "Simpson's Rule equals " << z << " when n = 8: " << '\n';
	cout << "|erf(1) - SR(n = 8)| = " << o << '\n';
	cout << "The rate of decrease from n = 1 to n = 2 is: " << (l - m) / l << '\n';
	cout << "The rate of decrease from n = 2 to n = 4 is: " << (m - n) / m << '\n';
	cout << "The rate of decrease from n = 4 to n = 8 is: " << (n - o) / n << '\n';

	/*Initializations for finding the error bound for each n*/
	double h1 = 1;
	double h2 = .5;
	double h4 = .25;
	double h8 = .125;
	cout << '\n';

	/*Question 3:*/
	cout << "Question 3: Give an upper bound on the error in terms of n. Are the results from the last problem consistent with the error bounds?" << '\n';
	cout << "Answer1: The error has an upperbound of ~ f4(0) / (180 * n^4) in terms of n." << '\n';
	cout << "Answer2:" << '\n';
	cout << "The upper bound error for n = 1 is " << (pow(h1, 4) * f4(0) / 180) << '\n';
	cout << "|erf(1) - SR(n = 1)| = " << l << '\n';
	cout << "The upper bound error for n = 2 is " << (pow(h2, 4) * f4(0) / 180) << '\n';
	cout << "|erf(1) - SR(n = 2)| = " << m << '\n';
	cout << "The upper bound error for n = 4 is " << (pow(h4, 4) * f4(0) / 180) << '\n';
	cout << "|erf(1) - SR(n = 4)| = " << n << '\n';
	cout << "The upper bound error for n = 8 is " << (pow(h8, 4) * f4(0) / 180) << '\n';
	cout << "|erf(1) - SR(n = 8)| = " << o << '\n';
	cout << "So for none of the n's, were the errors consistent with the error bounds." << '\n';
	cout << '\n';

	/*Question 4:*/
	cout << "Question 4: Determine what n should be to guarantee an error less than 10^-13." << '\n';
	cout << "Answer: n needs to be greater than " << pow(((f4(0) * pow(10, 13)) / 180), .25) << " to have an error < 10^-13." << '\n';
	cout << "I know this is not the right n because of the following test: n = 931 --> Simpson's Rule = " << setprecision(15) << SimpsonsRule(931, a, b) << " and the error = " << erf1 - SimpsonsRule(931, a, b);
}