#include <iostream>
using namespace std;

int main() {
	int T, H, W, N;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> H >> W >> N; //아니 근데 W는 도대체 왜 받는거임 쓰지도 않네;
		if (N % H == 0) //딱 나누어 떨어질 때 체크안하면 0으로 들어감
			cout << (H * 100) + (N / H) << endl;
		else
			cout << (N % H * 100) + (N / H + 1) << endl;
	}
}