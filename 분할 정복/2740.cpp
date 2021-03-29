#include <iostream>

using namespace std;

int matrixA[100][100];
int matrixB[100][100];
int result[100][100];

int main() {
    int N, M, K;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin >> matrixA[i][j];
    }

    cin >> M >> K;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++)
            cin >> matrixB[i][j];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            for (int k = 0; k < M; k++) {
                result[i][j] += (matrixA[i][k] * matrixB[k][j]);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++)
            cout << result[i][j] << ' ';
        cout << '\n';
    }
}