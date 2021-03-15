#include <iostream>
using namespace std;

bool isHan(int n) {
	int part[3];

	if (n < 100) //100미만이면 무조건 한수
		return true;
	else if (n == 1000) //1000은 안됨
		return false;
	else { //3자리 숫자들 한수인지 체크
		for (int i = 0; i < 3; i++) { //쪼갬
			part[i] = n % 10;
			n /= 10;
		}
		if ((part[0] - part[1]) == (part[1] - part[2])) //체크
			return true;
		else
			return false;
	}
}

int main() {
	int N, count = 0;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		if (isHan(i))
			count++;
	}
	cout << count << endl;
}