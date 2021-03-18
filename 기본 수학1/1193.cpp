#include <iostream>
using namespace std;

int main() {
	int X, f, b, pos = 1, i = 1;

	cin >> X;
	while (X > pos) { //숫자 있는 줄?을 찾음
		i++;
		pos += i;
	}
	if (i % 2 == 0) { //짝수 행의 수학적인 어쩌구...
		b = pos - X + 1;
		f = i - b + 1;
	}
	else { //홀수 행의 수학적인 어쩌구...
		f = pos - X + 1;
		b = i - f + 1;
	}
	cout << f << '/' << b << endl;
}