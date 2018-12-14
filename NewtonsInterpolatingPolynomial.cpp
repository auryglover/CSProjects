/*Arianna Glover*/
using namespace std;
#include <iostream>
#include <cmath>

long double Function(double x) {
	return 1 / (1 + (25 * pow(x, 2)));
}

long double PnXi(long double divideddifference[], long double nodes[], long double x, int n) {
	long double p = divideddifference[n];
	for (int j = n; j >= 1; j--) {
		p = p * (x - nodes[j - 1]) + divideddifference[j - 1];
	}
	return p;
}

long double Error(long double divideddifference[], long double nodes[], long double x, int n) {

	return Function(x) - PnXi(divideddifference, nodes, x, n);
}

void DividedDifference(long double nodes[], long double x, int n) {
	long double divideddifference[21];
	int k = 0;
	for (int i = 0; i <= n; i++) {
		divideddifference[i] = Function(nodes[i]);
	}
	while (k < n) {
		for (int j = n; j > k; j--) {
			divideddifference[j] = (divideddifference[j] - divideddifference[j - 1]) / (nodes[j] - nodes[j - k - 1]);
		}
		k++;
	}
	cout << "The Pn(.985) = " << PnXi(divideddifference, nodes, x, n) << '\n';
	cout << "The Error at x = .985 is " << Error(divideddifference, nodes, x, n) << '\n';
	cout << "The divided difference is {";
	for (int l = 0; l <= 20; l++) {
		cout << divideddifference[l] << ", ";
		if (l == 20) {
			cout << "}";
		}
	}
	cout << '\n' << '\n';
}

int main() {
	long double nodesa[21];
	long double nodesb[21];
	int n = 20;
	double pi = 3.1415926535897;
	for (int i = 0; i <= 20; i++) {
		nodesa[i] = (-1) + (i * (.1));
	}

	for (int j = 0; j <= 20; j++) {
		nodesb[j] = cos(((double)((2 * j) + 1) / (double)(2 * (n + 1)))*pi);
	}
	cout << "The chebyshev nodes are {";
	for (int z = 0; z <= 20; z++) {
		cout << nodesb[z] << ", ";
	}
	cout << "}" << '\n';
	cout << "F(.985) = " << Function(.985) << '\n';
	DividedDifference(nodesb, .985, 20);
	cout << "The uniform nodes are {";
	for (int y = 0; y <= 20; y++) {
		cout << nodesb[y] << ", ";
	}
	cout << "}" << '\n';
	DividedDifference(nodesa, .985, 20);
}

/*Question 4: Give an explanation of whether your results are consistent with the error bounds for each interpolation.*/
/*Answer: When this program is executed we see that the error for the interpolant from the uniform nodes are large while the error for the interpolant from the chebyshev nodes are relatively smaller.
This is because the interpolants for each nodes behave very differently at x = .985 and thus we see that the chebyshev nodes are optimal or better in this case than the uniform nodes.*/