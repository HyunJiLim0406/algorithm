#include <iostream>
using namespace std;

int main() {
	int A[9], max_pos, max = 0;

	for (int i = 0; i < 9; i++) {
		cin >> A[i];
		if (A[i] > max) {
			max = A[i];
			max_pos = i + 1;
		}
	}
	cout << max << '\n' << max_pos << endl;
}