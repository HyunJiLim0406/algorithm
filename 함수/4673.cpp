#include <iostream>
using namespace std;

int func(int n) {
	int sum = n;

	while (n != 0) {
		sum += (n % 10);
		n /= 10;
	}

	return sum;
}

int main() {
	int i;
	int num[10001];
	for (i = 0; i < 10001; i++)
		num[i] = 1;

	for (i = 0; i < 10001; i++) {
		if (func(i) < 10001)
			num[func(i)] = 0; //생성자가 있으면 0으로
	}
	for (i = 0; i < 10001; i++) {
		if (num[i] == 1)
			cout << i << endl;
	}
}