/*Arianna Glover*/

using namespace std;
#include <iostream>
#include <math.h>
#include <cmath>

/*Functions for Homework Here*/

/*a.*/
double FunctionNM(double x) {

	double a = pow(x, 3) - 2 * pow(x, 2) - 5;
	return a;
}

/*b.*/
//double FunctionNM (double x) {

//    double a = pow (x, 3) + 3 * pow (x, 2) - 1;
//    return a;
//}

/*c.*/
//double FunctionNM(double x) {

//    double a = x - cos(x);
//    return a;
//}

/*d.*/
//double FunctionNM(double x) {

//    double a = x - 0.8 - 0.2 * sin(x);
//    return a;
//}


/*Derivatives for Homework Here*/

/*a.*/
double Derivative(double x) {

	double a = 3 * pow(x, 2) - 4 * x;
	return a;
}

/*b.*/
//double Derivative (double x) {
//    double a = 3 * pow (x, 2) + 6 * x;
//    return a;
//}

/*c.*/
//double Derivative(double x) {
//    double a = 1 + sin(x);
//    return a;
//}

/*d.*/
//double Derivative(double x) {
//    double a = 1 + 0.2 * cos(x);
//    return a;
//}


/*Newton's Method*/
double NewtonsMethod(int i, double a, double b, double p) {

	/*Definitions */

	cout << '\n' << "a = " << a;
	cout << '\n' << "b = " << b;
	double pold;
	double tol = 1e-4;
	double fp = FunctionNM(p);
	double fpp = Derivative(p);
	cout << '\n' << "p" << i << " = " << p;
	cout << '\n' << "f(p) = " << fp;
	cout << '\n' << "f'(p) = " << fpp;

	/*Different Root Cases */
	/*Iteration Formula */
	pold = p;
	cout << '\n' << "f(p)/f'(p) = " << fp / fpp;
	p = p - (fp / fpp);
	cout << '\n' << "p" << i << " = " << p;

	if (abs(p - pold) <= tol) {
		cout << '\n' << "The root on the interval [" << a << "," << b << "] is " << p;
		return p;
	}

	else if (p < -50 || p > 50) {
		cout << '\n' << "There is no root on the interval [" << a << "," << b << "].";
		return 0;
	}

	else if (p > -50 && p < 50) {
		NewtonsMethod(i + 1, a, b, p);
	}
}

int main() {

	/*Intialization */
	double p;
	double a;
	double b;


	/*Entering p0 */

	/*a. */
	a = 1;
	b = 4;
	p = a + (b - a) / 2;

	/*b. */
	//a = -3;
	//b = -2;
	//p = a + (b - a) / 2;

	/*c. */
	//double pi = 3.1415926535897;
	// a = 0;
	//b = pi/2;
	//p = a + (b - a) / 2;

	/*d. */
	//double pi = 3.1415926535897;
	//a = 0;
	//b = pi/2;
	//p = a + (b - a) / 2;

	cout << '\n' << "I have computed that: ";
	NewtonsMethod(1, a, b, p);
}
