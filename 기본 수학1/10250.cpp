#include <iostream>
using namespace std;

int main() {
	int T, H, W, N;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> H >> W >> N; //�ƴ� �ٵ� W�� ����ü �� �޴°��� ������ �ʳ�;
		if (N % H == 0) //�� ������ ������ �� üũ���ϸ� 0���� ��
			cout << (H * 100) + (N / H) << endl;
		else
			cout << (N % H * 100) + (N / H + 1) << endl;
	}
}