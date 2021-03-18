#include <iostream>
using namespace std;

int main() {
	int N, cross = 0, max = 0;

	cin >> N;
	while (N > (6 * max + 1)) { //각 방의 최대? 숫자가 저거임
		cross++;
		max += cross;
	}
	cout << cross + 1 << endl;
}