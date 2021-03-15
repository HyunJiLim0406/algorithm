#include <iostream>
using namespace std;

int main() {
	int N, i, j, k;

	cin >> N;
	for (i = 1; i <= N; i++) {
		for (k = 1; k <= N - i; k++)
			cout << ' ';
		for (j = 1; j <= i; j++)
			cout << '*';
		cout << '\n';
	}
}