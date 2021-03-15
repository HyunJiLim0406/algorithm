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
			max = score[i]; //최댓값
		sum += score[i]; //걍 일일히 안하고 한번에 더해서 나누면 되던디
	}
	cout << sum / max * 100 / N << endl;
}