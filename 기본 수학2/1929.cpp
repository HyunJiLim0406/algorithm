#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int M, N, line, i, j;

	cin >> M >> N;
	bool* isPrime = new bool[N + 1];
	isPrime[0] = false;
	isPrime[1] = false;
	for (i = 2; i < N + 1; i++)
		isPrime[i] = true;
	line = sqrt(N) + 1; //제곱근까지만 체크해도 괜찮다고 함
	for (i = 2; i <= line; i++) {
		if (isPrime[i]) {
			for (j = 2 * i; j < N + 1; j += i) //내 다음부터 지우기
				isPrime[j] = false;
		}
	}
	for (i = M; i < N + 1; i++) {
		if (isPrime[i])
			cout << i << '\n';
	}
}