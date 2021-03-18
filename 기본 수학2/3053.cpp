#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

int main() {
	double R, u_R, t_R;

	cin >> R;
	u_R = R * R * M_PI;
	t_R = 2 * R * R;
	cout << fixed;
	cout.precision(6);
	cout << u_R << '\n' << t_R << endl;
}