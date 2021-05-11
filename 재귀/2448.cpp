#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<vector<char>> board;

void star(int N, pair<int, int> pos) {
    if (N == 3) { //별 입력
        int row = pos.first;
        int col = pos.second;
        board[row][col + 2] = '*';
        board[row + 1][col + 1] = board[row + 1][col + 3] = '*';
        for (int i = 0; i < 5; i++)
            board[row + 2][col + i] = '*';
        return;
    }
    star(N / 2, make_pair(pos.first, pos.second + N / 2)); //맨 위 삼각형
    star(N / 2, make_pair(pos.first + N / 2, pos.second)); //아래 왼쪽 삼각형
    star(N / 2, make_pair(pos.first + N / 2, pos.second + N)); //아래 오른쪽 삼각형
}

int main() {
    int N;

    cin >> N;
    board.assign(N, vector<char>(2 * N - 1, ' ')); //크기 할당
    star(N, make_pair(0, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (2 * N - 1); j++)
            cout << board[i][j];
        cout << '\n';
    }
}