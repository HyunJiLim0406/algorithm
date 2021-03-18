#include <iostream>
using namespace std;

int main() { //규칙찾기 문제
	int T;
	long x, y, dist, pos, result, jump;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> x >> y;
		dist = y - x;
		pos = 1;
		result = 1;
		jump = 0;
		while (pos < dist) {
			jump++;

			result++;
			pos += jump;
			if (pos >= dist)
				break;
			result++;
			pos += jump;
			if (pos >= dist)
				break;
		}
		if (pos > dist)
			result--;
		cout << result << '\n';
	}
}