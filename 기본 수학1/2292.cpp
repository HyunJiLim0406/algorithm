#include <iostream>
using namespace std;

int main() {
	int N, cross = 0, max = 0;

	cin >> N;
	while (N > (6 * max + 1)) { //�� ���� �ִ�? ���ڰ� ������
		cross++;
		max += cross;
	}
	cout << cross + 1 << endl;
}