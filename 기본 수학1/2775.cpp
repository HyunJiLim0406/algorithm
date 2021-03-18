#include <iostream>
using namespace std;

int live(int k, int n) {
	int people = 0;
	if (k == 1) {
		for (int i = 1; i <= n; i++)
			people += i;
	}
	else {
		for (int i = n; i >= 1; i--)
			people += live(k - 1, i);
	}
	return people;
}

int main() {
	int T, k, n;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> k >> n;
		cout << live(k, n) << endl;
	}
}