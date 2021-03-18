#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num) {
	if (num == 1)
		return false;
	else {
		for (int i = 2; i < num; i++) {
			if (num % i == 0) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	int T, n, f, b;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		f = n / 2;
		b = n / 2;
		while (true) {
			if (isPrime(f) && isPrime(b))
				break;
			f--;
			b++;
		}
		cout << f << ' ' << b << '\n';
	}
}