#include <iostream>
using namespace std;

int main() {
	int C, N, count;
	double sum;

	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> N;
		sum = 0.0;
		count = 0;
		int* stu_score = new int[N]; //���⿩�� N��ŭ �Ҵ��ϴ°� ������
		for (int j = 0; j < N; j++) {
			cin >> stu_score[j];
			sum += stu_score[j];
		}
		for (int j = 0; j < N; j++) {
			if (stu_score[j] > sum / N) //��� ���� �ֵ� ī��Ʈ
				count++;
		}
		cout << fixed; //�Ҽ��� ����
		cout.precision(3);
		cout << double(count) / double(N) * 100 << '%' << endl;
	}
}