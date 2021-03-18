#include <iostream>
using namespace std;

int main() {
	int x, y, w, h, x_min, y_min;

	cin >> x >> y >> w >> h;
	if (x < (w - x))
		x_min = x;
	else
		x_min = w - x;
	if (y < (h - y))
		y_min = y;
	else
		y_min = h - y;
	if (x_min < y_min)
		cout << x_min;
	else
		cout << y_min;
}