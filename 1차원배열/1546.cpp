#include <iostream>
using namespace std;

int main() {
	int N, max = -1, i;
	double sum = 0.0;

	cin >> N;
	int* score = new int[N];
	for (i = 0; i < N; i++) {
		cin >> score[i];
		if (score[i] > max)
			max = score[i]; //�ִ�
		sum += score[i]; //�� ������ ���ϰ� �ѹ��� ���ؼ� ������ �Ǵ���
	}
	cout << sum / max * 100 / N << endl;
}