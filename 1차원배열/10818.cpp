#include <iostream>
using namespace std;

int main() {
	int N, min = 1000001, max = -1000001;

	cin >> N;
	int* A = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (A[i] < min)
			min = A[i];
		if (A[i] > max) //else if 쓰면 오류
			max = A[i];
	}
	cout << min << ' ' << max << endl;
}