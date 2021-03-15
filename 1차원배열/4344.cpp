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
		int* stu_score = new int[N]; //띄어쓰기여도 N만큼 할당하는게 가능함
		for (int j = 0; j < N; j++) {
			cin >> stu_score[j];
			sum += stu_score[j];
		}
		for (int j = 0; j < N; j++) {
			if (stu_score[j] > sum / N) //평균 넘은 애들 카운트
				count++;
		}
		cout << fixed; //소수점 고정
		cout.precision(3);
		cout << double(count) / double(N) * 100 << '%' << endl;
	}
}