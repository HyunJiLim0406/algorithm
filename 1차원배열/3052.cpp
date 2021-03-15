#include <iostream>
using namespace std;

int main() {
	int num, remain[42], count = 0, i;
	for (i = 0; i < 42; i++)
		remain[i] = 0;

	for (i = 0; i < 10; i++) {
		cin >> num;
		int R = num % 42;
		remain[R]++;
	}
	for (i = 0; i < 42; i++) {
		if (remain[i] != 0) //해당 나머지가 있었으면 0이 아닐 것
			count++;
	}
	cout << count << endl;
}