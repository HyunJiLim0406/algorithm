#include <iostream>
using namespace std;

int main() {
	long long int A, B, C, x = 0;

	cin >> A >> B >> C;
	if (B >= C) {
		cout << -1 << endl;
	}
	else {
		cout << A / (C - B) + 1 << endl;
	}
}