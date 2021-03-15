#include <iostream>
using namespace std;

int main() {
	int N, count = 0, new_num = -1, sum, temp;
	int N_f, N_b;

	cin >> N;
	temp = N;
	while (N != new_num) {
		if (temp < 10) {
			N_f = 0;
			N_b = temp;
		}
		else {
			N_f = temp / 10;
			N_b = temp % 10;
		}
		sum = N_f + N_b;
		new_num = N_b * 10 + sum % 10;
		temp = new_num;
		count++;
	}
	cout << count << endl;
}