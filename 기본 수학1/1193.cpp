#include <iostream>
using namespace std;

int main() {
	int X, f, b, pos = 1, i = 1;

	cin >> X;
	while (X > pos) { //���� �ִ� ��?�� ã��
		i++;
		pos += i;
	}
	if (i % 2 == 0) { //¦�� ���� �������� ��¼��...
		b = pos - X + 1;
		f = i - b + 1;
	}
	else { //Ȧ�� ���� �������� ��¼��...
		f = pos - X + 1;
		b = i - f + 1;
	}
	cout << f << '/' << b << endl;
}