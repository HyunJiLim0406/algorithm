#include <iostream>
using namespace std;

int main() {
	int A, B, C, mul, result[10], i;
	for (i = 0; i < 10; i++)
		result[i] = 0;

	cin >> A >> B >> C;
	mul = A * B * C;
	while (mul != 0) {
		int remain = mul % 10;
		result[remain]++; //�� �ڸ����� ���� �����ϴ°� �ƴ϶� �ٷ� result �ø���
		mul /= 10;
	}
	for (i = 0; i < 10; i++)
		cout << result[i] << endl;
}