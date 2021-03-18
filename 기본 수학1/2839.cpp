#include <iostream>
using namespace std;

int main() {
	int N, remain, five, three;
	bool possible = false;

	cin >> N;
	five = N / 5;
	remain = N % 5;
	if (remain == 0 || remain == 3) { //0 or 3이면 바로
		three = remain / 3;
		possible = true;
	}
	else {
		while (five > 0) { //5키로 하나씩 빼서 3으로 나눌 수 있는지 확인
			five--;
			remain += 5;
			if (remain % 3 == 0) {
				three = remain / 3;
				possible = true;
				break;
			}
		}
	}
	if (possible)
		cout << five + three << endl;
	else
		cout << -1 << endl;
}