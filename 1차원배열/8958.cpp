#include <iostream>
#include <cstring> //이거 빼고 strlen 쓰면 컴파일 오류
using namespace std;

int main() {
	int N, score, sum;
	char ox[80];

	cin >> N;
	for (int i = 0; i < N; i++) {
		score = 0;
		sum = 0;
		cin >> ox;
		for (int j = 0; j < strlen(ox); j++) {
			switch (ox[j]) {
			case 'O':
				score++;
				break;
			case 'X':
				score = 0;
				break;
			default:
				break;
			}
			sum += score;
		}
		cout << sum << endl;
	}
}