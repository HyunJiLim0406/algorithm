#include <iostream>
using namespace std;

int find_pos(int* mark) {
	if (mark[0] == mark[1])
		return mark[2];
	else if (mark[0] == mark[2])
		return mark[1];
	else
		return mark[0];
}

int main() {
	int x[3], y[3];

	for (int i = 0; i < 3; i++)
		cin >> x[i] >> y[i];
	cout << find_pos(x) << ' ' << find_pos(y) << endl;
}