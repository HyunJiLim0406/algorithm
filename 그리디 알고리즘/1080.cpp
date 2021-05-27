#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N, M;
    string input;
    vector<vector<int>> A, B;

    cin >> N >> M;
    A.assign(N, vector<int>(M));
    B.assign(N, vector<int>(M));
    for (int i = 0; i < N * 2; i++) {
        cin >> input;
        for (int j = 0; j < M; j++)
            (i < N) ? A[i][j] = input[j] - '0' : B[i % N][j] = input[j] - '0';
    }

    int cnt = 0;
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 2; j++) {
            if (A[i][j] != B[i][j]) { //다르다면 3*3 뒤집기
                for (int k = i; k <= i + 2; k++) {
                    for (int l = j; l <= j + 2; l++)
                        A[k][l] ^= 1;
                }
                cnt++; //뒤집은 횟수 증가
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] != B[i][j]) { //가능한 뒤집기 전부 하고도 다르다면 뒤집기 불가능
                cnt = -1;
                break;
            }
        }
    }
    cout << cnt;
}