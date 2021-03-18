#include <iostream>
#include <memory.h>
using namespace std;

void star(int **matrix, int n, int x, int y) {
	int k = n / 3;

	if (n == 1) {
		matrix[x][y] = 1;
		return;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i != 1 || j != 1)
				star(matrix, k, x + k * i, y + k * j);
		}
	}
	return;
}

int main() {
	int N;

	cin >> N;
	int** matrix = new int* [N];
	for (int i = 0; i < N; i++) {
		matrix[i] = new int[N];
		memset(matrix[i], 0, sizeof(int) * N);
	}
	star(matrix, N, 0, 0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (matrix[i][j] == 1)
				cout << '*';
			else
				cout << ' ';
		}
		cout << endl;
	}
}