#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N, M;
    string input;

    cin >> N >> M;
    vector<vector<int>> board(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 0; j < M; j++)
            board[i][j] = input[j] - '0';
    }
    int size = 1; //가장 작은 크기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int gap = 1, num = board[i][j];
            while ((i + gap) < N && (j + gap) < M) { //범위 내에 있는 동안
                if (board[i + gap][j] == num && board[i][j + gap] == num && board[i + gap][j + gap] == num) //사각형 생성
                    size = max(size, gap + 1);
                gap++;
            }
        }
    }
    cout << size * size;
}