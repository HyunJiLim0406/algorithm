#include <iostream>
using namespace std;

int factorial(int N) {
	if (N == 0 || N == 1) // 0!=1 인거 까먹어서 한 번 틀림
		return 1;
	else
		return N * factorial(N - 1);
}

int main() {
	int N;

	cin >> N;
	cout << factorial(N) << '\n';
}
