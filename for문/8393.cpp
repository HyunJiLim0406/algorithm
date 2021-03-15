#include <iostream>
using namespace std;

int main() {
	int n, i, hap = 0;

	cin >> n;
	for (i = 1; i <= n; i++)
		hap += i;
	cout << hap << endl;
}