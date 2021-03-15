#include <iostream>
using namespace std;

int main() {
	int A, B;

	cin >> A >> B;
	while (A != 0 && B != 0) {
		cout << A + B << endl;
		cin >> A >> B;
	}
}