#include <iostream>
using namespace std;

void hanoi(int N, int source, int by, int destination) {
	if (N == 1) {
		cout << source << ' ' << destination << '\n';
	}
	else {
		hanoi(N - 1, source, destination, by); //n-1���� ������ 1->2
		cout << source << ' ' << destination << '\n'; //1���� ������ 1->3
		hanoi(N - 1, by, source, destination); //n-1���� ������ 2->3
	}
}

int main() {
	int N, cnt = 1;

	cin >> N;
	for (int i = 0; i < N; i++) //pow�� �Ǽ����̶� ������� ��¼�� �Ҹ� �� ���۾�
		cnt *= 2;
	cout << cnt - 1 << '\n';
	hanoi(N, 1, 2, 3);
}