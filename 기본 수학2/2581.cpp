#include <iostream>
using namespace std;

int main() {
	int M, N, min, sum = 0;
	bool isPrime, isFirst = false;

	cin >> M >> N;
	if (M == 1) //1은 소수가 아님
		M++;
	for (int i = M; i <= N; i++) {
		isPrime = true;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime) {
			sum += i;
			if (!isFirst) { //min 체크
				min = i;
				isFirst = true;
			}
		}
	}
	if (isFirst) //소수가 있었는지 체크
		cout << sum << '\n' << min << '\n';
	else
		cout << -1 << '\n';
}