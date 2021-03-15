#include <iostream>
using namespace std;

int main() {
	int N, sum = 0;
	char num[100];

	cin >> N >> num;
	for (int i = 0; i < N; i++) {
		int i_num = num[i] - '0';
		sum += i_num;
	}
	cout << sum << endl;
}