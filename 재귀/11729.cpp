#include <iostream>
using namespace std;

void hanoi(int N, int source, int by, int destination) {
	if (N == 1) {
		cout << source << ' ' << destination << '\n';
	}
	else {
		hanoi(N - 1, source, destination, by); //n-1개의 원판을 1->2
		cout << source << ' ' << destination << '\n'; //1개의 원판을 1->3
		hanoi(N - 1, by, source, destination); //n-1개의 원판을 2->3
	}
}

int main() {
	int N, cnt = 1;

	cin >> N;
	for (int i = 0; i < N; i++) //pow는 실수형이라 출력형식 어쩌구 할면 걍 수작업
		cnt *= 2;
	cout << cnt - 1 << '\n';
	hanoi(N, 1, 2, 3);
}