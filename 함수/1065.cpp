#include <iostream>
using namespace std;

bool isHan(int n) {
	int part[3];

	if (n < 100) //100�̸��̸� ������ �Ѽ�
		return true;
	else if (n == 1000) //1000�� �ȵ�
		return false;
	else { //3�ڸ� ���ڵ� �Ѽ����� üũ
		for (int i = 0; i < 3; i++) { //�ɰ�
			part[i] = n % 10;
			n /= 10;
		}
		if ((part[0] - part[1]) == (part[1] - part[2])) //üũ
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